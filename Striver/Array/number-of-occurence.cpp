class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        auto it1 = lower_bound(arr.begin(), arr.end(), target);
        if (it1 == arr.end() || *it1 != target) return 0;
        auto it2 = upper_bound(arr.begin(), arr.end(), target);
        
        return it2 - it1;
    }
};
