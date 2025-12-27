class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        return *max_element(arr.begin(), arr.end());
    }
};
