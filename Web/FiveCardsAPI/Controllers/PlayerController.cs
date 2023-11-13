using FiveCardsAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;

namespace FiveCardsAPI.Controllers
{
    [ApiController]
    public class PlayerController : Controller
    {
        [HttpGet]
        [Route("Players")]
        public List<Player> GetAllPlayers()
        {
            Configuration configuration = Configuration.GetConfiguration();
            List<Player> players = new List<Player>();

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
                        isComputer = reader.GetInt32(4),
                        isOnline = reader.GetInt32(5)
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
            Configuration configuration = Configuration.GetConfiguration();
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
                    player.isComputer = reader.GetInt32(4);
                    player.isOnline = reader.GetInt32(5);

                    return player;
                }
            }

            return player;
        }

        [HttpPost]
        [Route("Players/AddPlayer")]
        public int AddPlayer(Player player)
        {
            Configuration configuration = Configuration.GetConfiguration();
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("INSERT INTO Players (PlayerName, BoardID, PlayerCardsID, isComputer, isOnline)" +
                                         " VALUES (@PlayerName, @BoardID, @PlayerCardsID, @isComputer, @isOnline)", connection);
            command.Parameters.Clear();
            command.Parameters.AddWithValue("@PlayerName", player.PlayerName);
            command.Parameters.AddWithValue("@BoardID", player.BoardID);
            command.Parameters.AddWithValue("@PlayerCardsID", player.PlayerCardsID);
            command.Parameters.AddWithValue("@isComputer", player.isComputer);
            command.Parameters.AddWithValue("@isOnline", player.isOnline);

            return command.ExecuteNonQuery();
        }
    }
}
