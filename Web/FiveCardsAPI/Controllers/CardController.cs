using FiveCardsAPI.Enums;
using FiveCardsAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System.Collections.Generic;

namespace FiveCardsAPI.Controllers
{
    [ApiController]
    public class CardController : Controller
    {
        readonly Configuration configuration = Configuration.GetConfiguration();

        [HttpGet]
        [Route("Cards")]
        public List<Card> GetCards()
        {
            List<Card> cards = new();

            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM Cards", connection);

            using SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    var card = new Card
                    {
                        CardID = reader.GetInt32(0),
                        CardValue = reader.GetString(1),
                        CardTypeID = reader.GetInt32(2),
                    };

                    cards.Add(card);
                }
            }

            return cards;
        }

        [HttpGet]
        [Route("Cards/GetCardByCardValueAndCardTypeID")]
        public Card GetCardByCardValueAndCardTypeID(string CardValue, int CardTypeID)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM Cards "+
                                         "WHERE CardValue=@CardValue AND CardTypeID=@CardTypeID", connection);
            command.Parameters.AddWithValue("@CardValue", CardValue);
            command.Parameters.AddWithValue("@CardTypeID", CardTypeID);

            using SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    var card = new Card
                    {
                        CardID = reader.GetInt32(0),
                        CardValue = reader.GetString(1),
                        CardTypeID = reader.GetInt32(2),
                    };

                    return card;
                }
            }

            return new Card();
        }

        [HttpPost]
        [Route("Cards/AddCard")]
        public int AddCard(Card card)
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("INSERT INTO Cards (CardValue, CardTypeID)" +
                                         " VALUES (@CardValue, @CardTypeID)", connection);
            command.Parameters.Clear();
            command.Parameters.AddWithValue("@CardValue", card.CardValue);
            command.Parameters.AddWithValue("@CardTypeID", card.CardTypeID);

            return (int)AddingCard.Successful == command.ExecuteNonQuery() ? (int)AddingDeckCards.Successful : (int)AddingDeckCards.Failure;
        }
    }
}
