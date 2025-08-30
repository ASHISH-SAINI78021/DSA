// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxi = 0;
        int row = -1;
        
        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < m; j++){
                if (arr[i][j] == 1) count++;
            }
            if (count > maxi){
                maxi = count;
                row = i;
            }
        }
        
        return row;
    }
};