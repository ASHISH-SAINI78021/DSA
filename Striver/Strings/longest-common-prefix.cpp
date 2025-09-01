class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if (strs[0] == "") return ans;

        if (n == 1) return strs[0];
        int k = 0;

        for (int i = 0; i < strs[0].length(); i++){
            char ch = strs[0][i];
            ans.push_back(ch);
            int count = 1;
            for (int j = 1; j < n && k < strs[j].length(); j++){
                if (ch == strs[j][k]){
                    count++;
                }
                else break;
            }
            if (count != strs.size()){
                ans.pop_back();
                break ;
            }
            k++;
        }

        return ans;
    }
};