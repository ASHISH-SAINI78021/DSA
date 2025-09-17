class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i < n; i++){
            mp[arr[i]]++;
            if (mp[arr[i]] == 2){
                count++;
            }
            mp[brr[i]]++;
            if (mp[brr[i]] == 2){
                count++;
            } 
            ans[i] = count;
        }

        return ans;
    }
};