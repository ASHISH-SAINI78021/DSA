int Solution::lengthOfLastWord(const string s) {
    int n = s.length();
    string temp = "";
    int i = n - 1;
    while (i >= 0 && s[i] == ' ') i--;
    for (; i >= 0; i--){
        if (isalnum(s[i])){
            temp.push_back(s[i]);
        }
        else break ;
    }
    
    return temp.length();
}
