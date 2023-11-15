using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace FiveCardsAPI.Models
{
    public class Card
    {
        public int CardID { get; set; }
        public int CardValue { get; set; }
        public int CardTypeID { get; set; }
    }
}
