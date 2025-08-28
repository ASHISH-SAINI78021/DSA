class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        long long sum = 0;
        long long mx = -1;
        vector<int> ans, v;
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i]>=0){
                v.push_back(arr[i]);
                sum += arr[i];
                
            }
            else{
                if (sum > mx || ans.empty()) {
                    ans = v;
                    mx = sum;
                }
                v.clear();
                sum = 0;
            }
        }
        if (sum > mx || ans.empty()) {
            ans = v;
            mx = sum;
        }
        if (ans.empty()) return {-1};
        
        return ans;
    }
};