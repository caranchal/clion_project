using System;

public class ConsoleApp2
{
    public static void Main()
    {
        string encodedMessage = "r slkv mlylwb wvxlwvh gsrh nvhhztv";
        string decodedMessage = Decode(encodedMessage);
        Console.WriteLine(decodedMessage);

    }
    public static string Decode(string encoded)
    {
        char[] result = new char[encoded.Length];

        for (int i = 0; i < encoded.Length; i++)
        {
            char c = encoded[i];

            if (c == ' ')
            {
                result[i] = ' ';
            }
            else if (c >= 'a' && c <= 'z')
            {
                
                result[i] = (char)('z' - (c - 'a'));
            }
            else
            {
                
                result[i] = c;
            }
        }
        String s = result.ToString();
        return new string(result);
    }
}
