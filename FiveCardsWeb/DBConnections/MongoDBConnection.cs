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
        private readonly IMongoDatabase fiveCardsDatabase;
        private readonly string databaseName = "FiveCards";

        public MongoDBConnection(string connectionStr)
        {
            dbConnection = new MongoClient(connectionStr);
            fiveCardsDatabase = dbConnection.GetDatabase(databaseName);
        }

        public List<Player> GetAllPlayers()
        {
            var filter = Builders<Player>.Filter.Empty;
            return fiveCardsDatabase.GetCollection<Player>("Player").Find<Player>(filter).ToList();
        }

        public Player GetPlayerById(string idString)
        {
            var filter = Builders<Player>.Filter.Eq(player => player._id, new ObjectId(idString));
            return fiveCardsDatabase.GetCollection<Player>("Player").Find<Player>(filter).FirstOrDefault();
        }
    }
}
