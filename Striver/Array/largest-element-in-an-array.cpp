class Solution {
  public:
    int largest(vector<int> &arr) {
        return *max_element(arr.begin(), arr.end());
    }
};
