using System.Text.RegularExpressions;

internal class Program
{
    private static void Main()
    {
       
        string filePath = "emails.txt";

        string fileContent = File.ReadAllText(filePath);

        
        
        string pattern = @"\|([^|@\s]+@mail\.[^|\s]+)";

        MatchCollection matches = Regex.Matches(fileContent, pattern);

        
        foreach (Match match in matches)
        {
            if (match.Groups.Count > 1)
            {
                Console.WriteLine(match.Groups[1].Value);
            }
        }

    }
}
