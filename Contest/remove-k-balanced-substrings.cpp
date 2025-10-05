class Solution {
public:
    string removeSubstring(string s, int k) {
        string temp = "";
        for (int i = 0; i < k; i++) {
            temp += '(';
        }
        for (int i = 0; i < k; i++) {
            temp += ')';
        }

        string result = "";
        int temp_len = temp.length();
        int n = s.length();

        for (int i = 0; i < n; i++) {
            result.push_back(s[i]);
            if (result.length() >= temp_len) {
                if (result.compare(result.length() - temp_len, temp_len, temp) == 0) {
                    result.resize(result.length() - temp_len);
                }
            }
        }

        return result;
    }
};©leetcode