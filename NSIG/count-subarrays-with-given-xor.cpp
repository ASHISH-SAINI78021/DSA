class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        long count = 0;
        long Xor = 0;
        unordered_map<long, int> mp;
        for (int i = 0; i < n; i++){
            Xor = Xor ^ arr[i];
            if (Xor == k) count++;
            long target = Xor^k;
            if (mp.find(target) != mp.end()){
                count += mp[target];
            }
            
            mp[Xor]++;
        }
        
        return count;
    }
};