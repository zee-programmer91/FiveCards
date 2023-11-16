using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace FiveCardsAPI.Models
{
    public class Card
    {
        public int CardID { get; set; }
        public string CardValue { get; set; }
        public int CardTypeID { get; set; }

        public Card() { }
        public Card(string CardValue, int CardTypeID)
        {
            this.CardValue = CardValue;
            this.CardTypeID = CardTypeID;
        }

        public Card(int CardID, string CardValue, int CardTypeID)
        {
            this.CardID = CardID;
            this.CardValue = CardValue;
            this.CardTypeID = CardTypeID;
        }
    }
}
