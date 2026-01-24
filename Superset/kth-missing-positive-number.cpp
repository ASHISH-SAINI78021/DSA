class Solution {
public:
    bool solve(vector<int> &arr, int element){
        return binary_search(arr.begin(), arr.end(), element);
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 1;
        int end = arr[n - 1];
        int count = 0;

        for (int i = 1; i <= end; i++){
            if (!solve(arr, i)){
                count++;
            }
            if (count == k) return i;
        }

        return end + (k - count);
    }
};