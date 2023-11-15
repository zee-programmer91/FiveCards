using FiveCardsAPI.Controllers;
using FiveCardsAPI.Models;
using System;
using System.Collections.Generic;

namespace FiveCardsAPI.HelperFunctions
{
    public class Helper
    {
        public static List<int> RandomCardIndicesGenerator()
        {
            List<int> randomIndices = new();
            Random random = new();

            while (52 != randomIndices.Count)
            {
                int randomNumber = random.Next(0, 52);
                if (!randomIndices.Contains(randomNumber))
                {
                    randomIndices.Add(randomNumber);
                }
            }
            return randomIndices;
        }

        public static int DeckID(List<int> deckIDs)
        {
            int id = 0;

            for (int index = 0; index < 10000; index++)
            {
                if (!deckIDs.Contains(index))
                {
                    id = index;
                    break;
                }
            }
            return id;
        }

        public static KeyValuePair<List<int>, string> UpdateQueryCreator(object instance)
        {
            int count = 0;
            string updateQuery = "";
            List<int> changeOptions = new List<int>();
            switch (instance)
            {
                case Player:
                    updateQuery = PlayerUpdateQuery(updateQuery, instance, count, changeOptions);
                    break;
            };

            changeOptions.Sort();
            return new KeyValuePair<List<int>, string>(changeOptions, updateQuery);
        }

        private static string PlayerUpdateQuery(string updateQuery, object instance, int count, List<int> changeOptions)
        {
            updateQuery += "UPDATE Players SET ";
            Player updatedPlayerInfo = (Player)instance;
            Player oldPlayerInfo = new PlayerController().GetPlayerByID(updatedPlayerInfo.PlayerID);

            if (oldPlayerInfo.PlayerName != updatedPlayerInfo.PlayerName)
            {
                updateQuery += "PlayerName=@PlayerName";
                count++;
                changeOptions.Add(2);
            }
            if (oldPlayerInfo.BoardID != updatedPlayerInfo.BoardID)
            {
                updateQuery += (count != 0 ? ", BoardID=@BoardID" : "BoardID=@BoardID");
                count++;
                changeOptions.Add(3);
            }
            if (oldPlayerInfo.PlayerCardsID != updatedPlayerInfo.PlayerCardsID)
            {
                updateQuery += (count != 0 ? ", PlayerCardsID=@PlayerCardsID" : "PlayerCardsID=@PlayerCardsID");
                count++;
                changeOptions.Add(4);
            }
            if (oldPlayerInfo.IsComputer != updatedPlayerInfo.IsComputer)
            {
                updateQuery += (count != 0 ? ", IsComputer=@IsComputer" : "IsComputer=@IsComputer");
                count++;
                changeOptions.Add(5);
            }
            if (oldPlayerInfo.IsOnline != updatedPlayerInfo.IsOnline)
            {
                updateQuery += (count != 0 ? ", IsOnline=@IsOnline" : "IsOnline=@IsOnline");
                count++;
                changeOptions.Add(6);
            }

            if (count > 0)
            {
                updateQuery += " WHERE PlayerID=@PlayerID";
                changeOptions.Add(1);
            }

            return updateQuery;
        }
    }
}
