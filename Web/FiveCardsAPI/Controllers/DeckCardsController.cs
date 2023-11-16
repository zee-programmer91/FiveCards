using FiveCardsAPI.Enums;
using FiveCardsAPI.HelperFunctions;
using FiveCardsAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System.Collections.Generic;

namespace FiveCardsAPI.Controllers
{
    [ApiController]
    public class DeckCardsController : Controller
    {
        readonly Configuration configuration = Configuration.GetConfiguration();
        readonly List<Card> cards = new()
        {
            new Card( "A", 0), new Card( "A", 1), new Card( "A", 2), new Card( "A", 3),
            new Card( "2", 0), new Card( "2", 1), new Card( "2", 2), new Card( "2", 3),
            new Card( "3", 0), new Card( "3", 1), new Card( "3", 2), new Card( "3", 3),
            new Card( "4", 0), new Card( "4", 1), new Card( "4", 2), new Card( "4", 3),
            new Card( "5", 0), new Card( "5", 1), new Card( "5", 2), new Card( "5", 3),
            new Card( "6", 0), new Card( "6", 1), new Card( "6", 2), new Card( "6", 3),
            new Card( "7", 0), new Card( "7", 1), new Card( "7", 2), new Card( "7", 3),
            new Card( "8", 0), new Card( "8", 1), new Card( "8", 2), new Card( "8", 3),
            new Card( "9", 0), new Card( "9", 1), new Card( "9", 2), new Card( "9", 3),
            new Card( "10", 0), new Card( "10", 1), new Card( "10", 2), new Card( "10", 3),
            new Card( "J", 0), new Card( "J", 1), new Card( "J", 2), new Card( "J", 3),
            new Card( "Q", 0), new Card( "Q", 1), new Card( "Q", 2), new Card( "Q", 3),
            new Card( "K", 0), new Card( "K", 1), new Card( "K", 2), new Card( "K", 3),
        };

        [HttpGet]
        [Route("DeckCards")]
        public List<DeckCards> GetDeckCards()
        {
            List<DeckCards> deckCards = new();

            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var command = new SqlCommand("SELECT * FROM DeckCards", connection);

            using SqlDataReader reader = command.ExecuteReader();
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    var deckCard = new DeckCards
                    {
                        DeckCardsID = reader.GetInt32(0),
                        DeckID = reader.GetInt32(1),
                        CardID = reader.GetInt32(2),
                    };

                    deckCards.Add(deckCard);
                }
            }

            return deckCards;
        }

        [HttpPost]
        [Route("DeckCards/AddDeckCards")]
        public int AddDeckCards()
        {
            using var connection = new SqlConnection(configuration.ConnectionStrings["AZURE_SQL_CONNECTIONSTRING"]);
            connection.Open();

            var cardIndices = Helper.RandomCardIndicesGenerator();
            CardController cardController = new();
            DeckController deckController = new();
            List<int> deckIDs = new();

            var decks = new DeckController().GetDecks();

            foreach (Deck deck in decks) deckIDs.Add(deck.DeckNumber);

            var DeckNumber = Helper.DeckID(deckIDs);
            //  Insert Deck
            var result = deckController.AddDeck(DeckNumber);

            if ((int)AddingDeck.Failure == result) return (int)AddingDeck.Failure;

            // Insert Cards
            foreach (int cardIndex in cardIndices)
            {
                var card = cards[cardIndex];
                result = cardController.AddCard(card);
                var addedCard = cardController.GetCardByCardValueAndCardTypeID(card.CardValue, card.CardTypeID);

                if ((int)AddingCard.Failure == result) return (int)AddingCard.Failure;

                var command = new SqlCommand("INSERT INTO DeckCards (DeckNumber, CardID)" +
                                             " VALUES (@DeckNumber, @CardID)", connection);

                command.Parameters.Clear();
                command.Parameters.AddWithValue("@DeckNumber", DeckNumber);
                command.Parameters.AddWithValue("@CardID", addedCard.CardID);
                result = command.ExecuteNonQuery();

                if ((int)AddingDeckCards.Failure == result) return (int)AddingDeckCards.Failure;
            }

            return (int)AddingDeckCards.Successful;
        }
    }
}
