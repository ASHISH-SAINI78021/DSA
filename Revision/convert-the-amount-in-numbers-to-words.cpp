vector<string> one = {"", "one-", "two-", "three-", "four-", "five-", "six-", "seven-", "eight-", "nine-", "ten-", "eleven-", "twelve-", "thirteen-", "fourteen-", "fifteen-", "sixteen-", "seventeen-", "eighteen-", "nineteen-"};

vector<string> ten = {"", "", "twenty-", "thirty-", "forty-", "fifty-", "sixty-", "seventy-", "eighty-", "ninety-"};

string makeNumToString(int n, string attach){
    string str = "";
    if (n > 19){
        str += ten[n/10] + one[n%10];
    }
    else str += one[n];
    
    if (n){
        str += attach;
    }
    
    return str;
}

string result(int n){
    string str = "";
    str += makeNumToString((n/10000000), "crore-");
    str += makeNumToString((n/100000)%100, "lakh-");
    str += makeNumToString((n/1000)%100, "thousand-");
    str += makeNumToString((n/100)%10, "hundred-");

    if (n > 100 && n % 100){
        str += "and-";
    }

    str += makeNumToString(n % 100, "");
    
    if (!str.empty()) str.pop_back(); // remove last '-'
    
    return str;
}

int Solution::solve(string s, string t) {
    int num = stoi(s);
    string ans = result(num);

    if (ans.compare(t) == 0) return 1;

    return 0;
}
