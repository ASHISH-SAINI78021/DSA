class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        if (n == 1) return ans;

        int j = 1;
        while (j < n){
            vector<int> temp;
            temp.push_back(1);
            for (int i = 0; i < ans.size() - 1; i++){
                int sum = ans[ans.size() - 1][i] + ans[ans.size() - 1][i + 1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ans.push_back(temp);
            j++;
        }

        return ans;
    }
};