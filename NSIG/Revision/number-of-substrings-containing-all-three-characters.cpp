class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int a = -1;
        int b = -1;
        int c = -1;
        int count = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'a') a = i;
            else if (s[i] == 'b') b = i;
            else if (s[i] == 'c') c = i;
            
            if (a != -1 && b != -1 && c != -1){
                count += 1 + min({a, b, c});
            }
        }

        return count;
    }
};