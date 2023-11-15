using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace FiveCardsAPI.Models
{
    public class BoardPlayers
    {
        public int BoardPlayersID { get; set; }
        public int BoardID { get; set; }
        public int PlayerID { get; set; }
    }
}
