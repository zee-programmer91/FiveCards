using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace FiveCardsAPI.Models
{
    public class Player
    {
        public int PlayerID { get; set; }
        public string PlayerName { get; set; }
        public int BoardID { get; set; }
        public int PlayerCardsID { get; set; }
        public int IsComputer { get; set; }
        public int IsOnline { get; set; }
        public int Status { get; set; }
    }
}
