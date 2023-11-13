using System.Collections.Generic;
using System.IO;
using System.Text.Json;

namespace FiveCardsAPI
{
    public class Configuration
    {
        static string configurationContext = File.ReadAllText(@"./appsettings.json");
        public Dictionary<string, Dictionary<string, string>> Logging { get; set; }
        public string AllowedHosts { get; set; }
        public Dictionary<string, string> ConnectionStrings { get; set; }
    
        public static Configuration GetConfiguration()
        {
            return JsonSerializer.Deserialize<Configuration>(configurationContext);
        }
    }
}
