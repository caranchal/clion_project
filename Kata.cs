using System;

public class AlcoholCheck
{
    public static void Main()
    {
        var drinks1 = new[]
        {
            new[] { 15.5, 568.0 }
            
        };
        String stopDrinking = "23:00";
        String planToDrive = "6:45";
        

        var res = CanDrive(
            drinks1,
            stopDrinking,
            planToDrive);
        Console.WriteLine($"Всего единиц: {res.Item1}, Можно ехать: {res.Item2}");
    }

    public static (double, bool) CanDrive(double[][] drinks, string stopDrinking, string planToDrive)
    {
        
        double total = 0;
        foreach (var drink in drinks)
        {
            total += drink[0] * drink[1] / 1000;
        }
        total = Math.Round(total, 2);

        
        var stop = TimeSpan.Parse(stopDrinking);
        var drive = TimeSpan.Parse(planToDrive);

        
        double hours;
        if (stop <= drive)
        {
            hours = (drive - stop).TotalHours;
        }
        else
        {
            hours = (24 - stop.TotalHours) + drive.TotalHours;
        }

        
        bool ok = total <= hours;

        return (total, ok);
    }
}
