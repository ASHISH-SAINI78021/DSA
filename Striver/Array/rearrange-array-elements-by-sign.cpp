class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int negIndex = 1;
        int posIndex = 0;

        for (int i = 0; i < n; i++){
            if (arr[i] > 0){
                ans[posIndex] = arr[i];
                posIndex += 2;
            }
            else {
                ans[negIndex] = arr[i];
                negIndex += 2;
            }
        }

        return ans;
    }
};