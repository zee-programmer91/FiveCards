using FiveCardsAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System.Collections.Generic;

namespace FiveCardsAPI.Controllers
{
    [ApiController]
    public class DeckController : Controller
    {
        readonly Configuration configuration = Configuration.GetConfiguration();

        [HttpGet]
        [Route("Decks")]
        public List<Deck> GetDecks()
        {
            List<Deck> decks = new();

            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM Decks", connection);

            using SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    var deck = new Deck
                    {
                        DeckID = reader.GetInt32(0),
                        DeckNumber = reader.GetInt32(1)
                    };

                    decks.Add(deck);
                }
            }

            return decks;
        }

        [HttpPost]
        [Route("Decks/AddDeck")]
        public int AddDeck(int deckNUmber)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("INSERT INTO Decks(DeckNUmber) VALUES(@DeckNUmber)", connection);
            command.Parameters.Clear();
            command.Parameters.AddWithValue("@DeckNUmber", deckNUmber);

            return command.ExecuteNonQuery();
        }
    }
}
