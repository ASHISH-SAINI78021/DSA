// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        string yes = "Yes";
        string no = "No";
        vector<int> brr(arr, arr + n);
        sort(brr.begin(), brr.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[brr[i]] = i;
        }
        
        for (int i = 0; i < n; i++){
            if (abs(mp[arr[i]] - i) > k) return no;
        }
        
        return yes;
    }
};