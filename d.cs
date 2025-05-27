using System;
using System.Collections.Generic;
public partial class Kata
{
  public static string ChineseZodiac(int year)
  {
    List<string> Animals = new List<string>() { "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                                            "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
List<string> Elements = new List<string>() { "Wood", "Fire", "Earth", "Metal", "Water" };

           
int anIndex = (year - 1924) % 12;
if (anIndex < 0) anIndex += 12;


int elCycle = (year - 1924) % 10;
if (elCycle < 0) elCycle += 10;
int elementIndex = elCycle / 2;


elementIndex = elementIndex % 5;

return $"{Elements[elementIndex]} {Animals[anIndex]}";
  }
}
