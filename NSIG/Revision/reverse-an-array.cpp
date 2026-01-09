class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        if (n <= 1) return ;
        while (i <= j){
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
};