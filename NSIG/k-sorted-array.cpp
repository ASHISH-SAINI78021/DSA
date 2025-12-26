// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        string yes = "Yes";
        string no = "No";
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++){
            if (abs(i - mp[arr[i]]) > k) return no;
        }
        
        return yes;
    }
};


// Brute Force
// T.C -> O(n*n)
// S.C -> O(1)

// Optimal Approach
// Sort the array
// before sorting, store the indices w.r.t its element
// now find distance between the sorted and orginal one.
// if it is greater than k -> no otherwise yes