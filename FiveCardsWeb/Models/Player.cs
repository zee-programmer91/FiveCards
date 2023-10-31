using System;
using System.Collections.Generic;
using System.Linq;
using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;

namespace FiveCardsWeb.Models
{
    [BsonIgnoreExtraElements]
    class Player
    {
        public ObjectId _id { get; set; }
        public string playerName { get; set; }
        public Int32 boardID { get; set; }
        public Int32 playerCarsID { get; set; }
        public bool isComputer { get; set; }
        public bool isOnline { get; set; }

        [BsonConstructor]
        public Player(ObjectId _ID, string PlayerName, Int32 BoardID, Int32 PlayerCarsID, bool IsComputer, bool IsOnline)
        {
            _id = _ID;
            playerName = PlayerName;
            boardID = BoardID;
            playerCarsID = PlayerCarsID;
            isComputer = IsComputer;
            isOnline = IsOnline;
        }
    }
}
