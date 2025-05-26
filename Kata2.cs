using System.Collections.Generic;

internal class Program
{
    private static void Main(string[] args)
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        Console.WriteLine("Hello, World!");
        String s = "Announcing the Macbook Air Guitar";
        String g = $"Result: {HeavyMetalUmlauts(s)}";
        Console.WriteLine(g);
        int[] arr1 = { 33, 2, 3, 37, 38, 40, 12, 10, 43, 44, 47, 49, 8, 19, 22, 24, 26, 28, 29, 30 };
        int[] arr2 = { 1, 34, 17, 7, 9, 10, 43, 49, 22, 27, 28 };
        int[] res = Process2Arrays(arr1 , arr2);
        foreach(int i in res)
            Console.WriteLine(i);

        Console.WriteLine(ValidatePin("435f"));

        String[] b = Solution("abcde");
       // foreach(String i in b) Console.WriteLine(i);
        b.ToList().ForEach(i => Console.WriteLine(i));
    }
    
    public static String HeavyMetalUmlauts(String text)
    {
        String result = "";
        
        for (int i = 0; i < text.Length - 1; i++)
        {
            switch(text[i])
            {
                case 'A':
                    result += "\u00c4";
                    break;
                case 'O':
                    result += "\u00d6";
                    break;
                case 'a':
                    result += "\u00e4";
                    break;
                case 'o':
                    result += "\u00f6";
                    break;
                case 'E':
                    result += "\u00cb";
                    break;
                case 'U':
                    result += "\u00dc";
                    break;
                case 'e':
                    result += "\u00eb";
                    break;
                case 'u':
                    result += "\u00fc";
                    break;
                case 'I':
                    result += "\u00cf";
                    break;
                case 'Y':
                    result += "\u0178";
                    break;
                case 'i':
                    result += "\u00ef";
                    break;
                case 'y':
                    result += "\u00ff";
                    break;
                default:
                    result += text[i];
                    break;

            }
            
        }
        
        
        return result;
    }
    public static int[] Process2Arrays(int[] arr1, int[] arr2)
    {
        var z = new int[arr1.Length + arr2.Length];
        arr1.CopyTo(z, 0);
        arr2.CopyTo(z, arr1.Length);
        int[] result = new int[4];

        int dup = result[0] = z.Count() - z.Distinct().Count();
        result[1] = arr1.Except(arr2).Count() + arr2.Except(arr1).Count();
        result[2] = arr1.Length - dup;
        result[3] = arr2.Length - dup;
       return result;

    }
    public static bool ValidatePin(string pin)
    {
        return (pin.Length == 4 || pin.Length == 6) && pin.All(char.IsDigit);
    }

    public static string[] Solution(string str)
    {
        
        String[] strings = new String[str.Length];
        if(str.Length % 2 == 0)
        {
            for (int i = 0; i < str.Length; i += 2)
            {
                strings[i] = str.Substring(i, 2);
            }
        }
        if(str.Length % 2 != 0)
        {
            for (int i = 0; i < str.Length; i += 2)
            {
                if (str.Length - i  == 1)
                {
                    strings[i] = str[i].ToString();
                    strings[i + 1] = "_";

                    break;
                }
                strings[i] = str.Substring(i, 2);
            }
        }
        return strings;
    }
}
