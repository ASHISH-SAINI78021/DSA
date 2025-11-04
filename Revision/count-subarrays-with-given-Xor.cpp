class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        long Xor = 0;
        long count = 0;
        unordered_map<long, long> mp;
        for (int i = 0; i < n; i++){
            Xor = Xor ^ arr[i];
            if (Xor == k) count++;
            long required = k ^ Xor;
            if (mp.find(required) != mp.end()){
                count += mp[required];
            }
            mp[Xor]++;
        }
        
        return count;
    }
};