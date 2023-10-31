using System;
using System.Collections.Generic;
using MongoDB.Driver;
using MongoDB.Bson;
using FiveCardsWeb.Models;
using MongoDB.Bson.Serialization;

namespace FiveCardsWeb
{
    class Program
    {
        static void Main(string[] args)
        {
            BsonClassMap.RegisterClassMap<Player>(classMap =>
            {
                classMap.MapMember(p => p._id);
                classMap.MapMember(p => p.playerName);
                classMap.MapMember(p => p.boardID);
                classMap.MapMember(p => p.playerCarsID);
                classMap.MapMember(p => p.isComputer);
                classMap.MapMember(p => p.isOnline);
            });

            string connectionString = "mongodb+srv://fivecards:pqcyh28LvGx66trT@cluster0.rmcrpno.mongodb.net/?retryWrites=true&w=majority";
            MongoDBConnection mongoDBConnection = new MongoDBConnection(connectionString);

            var player = mongoDBConnection.GetPlayerById("65410bcbfd9998d423349253");
            Console.WriteLine("Grades collection: "+ player);
        }
    }
}
    