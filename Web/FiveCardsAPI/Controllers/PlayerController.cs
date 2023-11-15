using FiveCardsAPI.HelperFunctions;
using FiveCardsAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System.Collections.Generic;
using FiveCardsAPI.Enums;

namespace FiveCardsAPI.Controllers
{
    [ApiController]
    public class PlayerController : Controller
    {
        readonly Configuration configuration = Configuration.GetConfiguration();

        [HttpGet]
        [Route("Players")]
        public List<Player> GetPlayers()
        {
            List<Player> players = new();

            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM Players", connection);

            using SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    var player = new Player
                    {
                        PlayerID = reader.GetInt32(0),
                        PlayerName = reader.GetString(1),
                        BoardID = reader.GetInt32(2),
                        PlayerCardsID = reader.GetInt32(3),
                        IsComputer = reader.GetInt32(4),
                        IsOnline = reader.GetInt32(5),
                        Status = reader.GetInt32(6)
                    };

                    players.Add(player);
                }
            }

            return players;
        }

        [HttpGet]
        [Route("Players/GetPlayerByID")]
        public Player GetPlayerByID(int id)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM Players WHERE PlayerID=@id", connection);
            command.Parameters.Clear();
            command.Parameters.AddWithValue("@id", id);

            using SqlDataReader reader = command.ExecuteReader();
            Player player = new();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    player.PlayerID = reader.GetInt32(0);
                    player.PlayerName = reader.GetString(1);
                    player.BoardID = reader.GetInt32(2);
                    player.PlayerCardsID = reader.GetInt32(3);
                    player.IsComputer = reader.GetInt32(4);
                    player.IsOnline = reader.GetInt32(5);

                    return player;
                }
            }

            return player;
        }

        [HttpPost]
        [Route("Players/AddPlayer")]
        public int AddPlayer(Player player)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("INSERT INTO Players (PlayerName, BoardID, PlayerCardsID, IsComputer, IsOnline)" +
                                         " VALUES (@PlayerName, @BoardID, @PlayerCardsID, @IsComputer, @IsOnline)", connection);
            command.Parameters.Clear();
            command.Parameters.AddWithValue("@PlayerName", player.PlayerName);
            command.Parameters.AddWithValue("@BoardID", player.BoardID);
            command.Parameters.AddWithValue("@PlayerCardsID", player.PlayerCardsID);
            command.Parameters.AddWithValue("@IsComputer", player.IsComputer);
            command.Parameters.AddWithValue("@IsOnline", player.IsOnline);

            return command.ExecuteNonQuery();
        }

        [HttpPost]
        [Route("Players/UpdatePlayer")]
        public int UpdatePlayer(Player player)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var result = Helper.UpdateQueryCreator(player);
            if ("UPDATE Players SET " == result.Value)
                return 0;

            var command = new SqlCommand(result.Value, connection);
            command.Parameters.Clear();

            foreach (int keyNo in result.Key)
            {
                switch (keyNo)
                {
                    case (int)PlayerColumns.PlayerID:
                        command.Parameters.AddWithValue("@PlayerID", player.PlayerID);
                        break;
                    case (int)PlayerColumns.PlayerName:
                        command.Parameters.AddWithValue("@PlayerName", player.PlayerName);
                        break;
                    case (int)PlayerColumns.BoardID:
                        command.Parameters.AddWithValue("@BoardID", player.BoardID);
                        break;
                    case (int)PlayerColumns.PlayerCardsID:
                        command.Parameters.AddWithValue("@PlayerID", player.PlayerCardsID);
                        break;
                    case (int)PlayerColumns.IsComputer:
                        command.Parameters.AddWithValue("@IsComputer", player.IsComputer);
                        break;
                    case (int)PlayerColumns.IsOnline:
                        command.Parameters.AddWithValue("@IsOnline", player.IsOnline);
                        break;
                };
            }

            return command.ExecuteNonQuery();
        }

        [HttpPost]
        [Route("Players/SoftDeletePlayerByID")]
        public int SoftDeletePlayerByID(int id)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("UPDATE Players SET Status=0 WHERE PlayerID=@PlayerID", connection);
            command.Parameters.Clear();
            command.Parameters.AddWithValue("@PlayerID", id);

            return command.ExecuteNonQuery();
        }

        [HttpPost]
        [Route("Players/SoftDeleteAllPlayers")]
        public int SoftDeleteAllPlayers()
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("UPDATE Players SET Status=0", connection);
            command.Parameters.Clear();

            return command.ExecuteNonQuery();
        }
    }
}
