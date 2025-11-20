string Solution::convert(string s, int k) {
    if (k == 1) return s;
    string ans = "";
    if (k <= 0) return ans;
    int n = s.length();
    vector<string> result(k, "");
    int j = 0;
    bool topToBottom = true;
    for (int i = 0; i < n; i++){
        if (topToBottom){
            result[j++] += s[i];
        }
        else 
            result[j--] += s[i];
            
        if (j == k){
            j -= 2;
            topToBottom = false;
        }
        if (j == -1){
            j += 2;
            topToBottom = true;
        }
    }
    
    for (auto it : result) ans += it;
    
    return ans;
}
