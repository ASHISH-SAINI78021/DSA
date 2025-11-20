int Solution::strStr(const string a, const string b) {
    int n = a.length();
    int m = b.length();
    if (n == 0 || m == 0) return -1;
    
    for (int i = 0; i < n; i++){
        string temp;
        for (int j = i; j < n; j++){
            temp += a[j];
            if (temp == b) return i;
        }
    }
    
    return -1;
}