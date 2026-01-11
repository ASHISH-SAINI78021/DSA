class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        if (n == 1) return strs[0];
        int k = 0;

        for (int i = 0; i < strs[0].size(); i++){
            int count = 0;
            for (int j = 0; j < n - 1; j++){
                if (strs[0][k] == strs[j + 1][k]){
                    count++;
                }
                else break ;
            }
            // cout << count << " ";
            if (count != n - 1){
                return ans;
            }
            ans = strs[0].substr(0, i + 1);
            // cout << ans << " ";
            k++;
        }

        return ans;
    }
};