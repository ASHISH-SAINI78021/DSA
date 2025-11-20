bool isValid(string part){
    if (part.empty() || part.size() > 3) return false;
    if (part[0] == '0' && part.size() > 1) return false;
    int value = stoi(part);
    
    return value >= 0 && value <= 255;
}
vector<string> Solution::restoreIpAddresses(string s) {
    int n = s.length();
    vector<string> ans;
    
    for (int i = 1; i <= 3; i++){
        for (int j = i + 1; j <= i + 3 && j < n; j++){
            for (int k = j + 1; k <= j + 3 && k < n; k++){
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string c = s.substr(j, k - j);
                string d = s.substr(k);
                
                if (isValid(a) && isValid(b) && isValid(c) && isValid(d)){
                    ans.push_back(a + '.' + b + '.' + c + '.' + d);
                }
            }
        }
    }
    
    return ans;
}
