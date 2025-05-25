using System;

public class ConsoleApp2
{
    public static void Main()
    {
        Console.WriteLine(CuckooClock("03:38", 19));
        
        Console.WriteLine(CuckooClock("01:00", 1));  

    }
    public static string CuckooClock(string initialTime, int n)
    {

        string[] parts = initialTime.Split(':');
        int hours = int.Parse(parts[0]);
        int minutes = int.Parse(parts[1]);

        int count = 0;

        while (true)
        {
          
            if (count >= n)
            {
                return $"{hours:D2}:{minutes:D2}";
            }

            
            if (minutes == 0)
            {
                
                count += hours;
                if (count >= n) return $"{hours:D2}:00";
            }
            else if (minutes == 15 || minutes == 30 || minutes == 45)
            {
            
                count += 1;
            }

          
            if (count >= n)
            {
                return $"{hours:D2}:{minutes:D2}";
            }

           
            minutes++;
            if (minutes == 60)
            {
                minutes = 0;
                hours++;
                if (hours == 13) hours = 1;
            }
        }
    }
}
