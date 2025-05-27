public static List<string> Top3(string text)
{
    var wordCounts = new Dictionary<string, int>();
    var wordPattern = new Regex(@"([a-zA-Z']+)");

    foreach (Match match in wordPattern.Matches(text.ToLower()))
    {
        string word = match.Value;
        if (word.All(c => c == '\'')) continue;
        if (wordCounts.ContainsKey(word))
            wordCounts[word]++;
        else
            wordCounts[word] = 1;
    }

    return wordCounts
        .OrderByDescending(pair => pair.Value)
        .Take(3)
        .Select(pair => pair.Key)
        .ToList();
}
