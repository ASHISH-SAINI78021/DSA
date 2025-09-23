class Solution {
public:
    int solve(vector<int> &arr, int i, int j){
        // base case
        if (i > j) return 0;

        // solution for one case 
        int ans1 = arr[i] + max(solve(arr, i + 2, j), solve(arr, i + 1, j - 1));
        int ans2 = arr[j] + max(solve(arr, i + 2, j - 1), solve(arr, i, j - 2));

        return max(ans1, ans2);
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int i = 0;
        int j = n - 1;

        int ans = solve(piles, i, j);

        return ans;
    }
};