class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1){
            return ans;
        }
        int j = 1;
        while (j < numRows){
            vector<int> result;
            result.push_back(1);
            for (int i = 0; i < ans[ans.size() - 1].size() - 1; i++){
                int sum = ans[ans.size() - 1][i] + ans[ans.size() - 1][i + 1];
                result.push_back(sum);
            }
            result.push_back(1);
            ans.push_back(result);
            j++;
        }

        return ans;
    }
};