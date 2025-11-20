string Solution::intToRoman(int n) {
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    
    string result = "";
    for (auto it : roman){
        while (n >= it.first){
            n -= it.first;
            result += it.second;
        }
    }
    
    return result;
}