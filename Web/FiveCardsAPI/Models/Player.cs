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
        public int isComputer { get; set; }
        public int isOnline { get; set; }
    }
}
