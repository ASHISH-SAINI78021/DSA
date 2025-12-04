class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<string> result(numRows, "");
        bool topToBottom = true;
        int k = 0;
        string ans = "";
        if (numRows == 1) return s;

        for (int i = 0; i < n; i++){
            if (topToBottom && k < numRows){
                result[k++] += s[i];
            }
            else if (!topToBottom && k < numRows) {
                result[k--] += s[i];
            }
            if (k == numRows){
                k -= 2;
                topToBottom = false;
            }
            if (k == -1){
                k = 1;
                topToBottom = true;
            }
        }

        for (auto it : result) ans += it;

        return ans;
    }
};