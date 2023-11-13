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
    [Route("[controller]")]
    public class PlayerController : Controller
    {
        [HttpGet]
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
    }
}
