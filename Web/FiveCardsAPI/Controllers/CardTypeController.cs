using FiveCardsAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System.Collections.Generic;

namespace FiveCardsAPI.Controllers
{
    [ApiController]
    public class CardTypeController : Controller
    {
        readonly Configuration configuration = Configuration.GetConfiguration();

        [HttpGet]
        [Route("CardTypes")]
        public List<CardType> GetCardTypes()
        {
            List<CardType> cardTypes = new();

            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM CardTypes", connection);

            using SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    var cardType = new CardType
                    {
                        CardTypeID = reader.GetInt32(0),
                        Type = reader.GetString(1)
                    };

                    cardTypes.Add(cardType);
                }
            }

            return cardTypes;
        }
    }
}
