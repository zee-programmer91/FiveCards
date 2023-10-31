using System;
using System.Collections.Generic;
using System.Linq;
using MongoDB.Driver;
using MongoDB.Bson;
using System.Threading.Tasks;
using FiveCardsWeb.Models;

namespace FiveCardsWeb
{
    class MongoDBConnection
    {
        private readonly MongoClient dbConnection;
        private readonly string databaseName = "FiveCards";

        public MongoDBConnection(string connectionStr)
        {
            dbConnection = new MongoClient(connectionStr);
        }

        public Player GetPlayerById(string idString)
        {
            var fiveCardsDatabase = dbConnection.GetDatabase(databaseName);
            var filter = Builders<Player>.Filter.Eq(player => player._id, new ObjectId(idString));
            return fiveCardsDatabase.GetCollection<Player>("Player").Find<Player>(filter).FirstOrDefault();
        }
    }
}
