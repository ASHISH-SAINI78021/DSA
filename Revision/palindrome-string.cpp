int Solution::isPalindrome(string s) {
    int n = s.length();
    string temp = "";
    for (int i = 0; i < n; i++){
        if (isalnum(s[i])){
            temp += tolower(s[i]);
        }
    }
    
    // cout << temp << endl;
    
    int i = 0;
    int j = temp.size() - 1;
    while (i <= j){
        if (temp[i] != temp[j]) return 0;
        i++;j--;
    }
    
    return 1;
}
