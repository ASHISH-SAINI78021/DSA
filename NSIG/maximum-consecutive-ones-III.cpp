class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;
        int maxi = 0;

        while (r < n){
            if (nums[r] == 0) count++;
            while (count > k){
                if (nums[l] == 0) count--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};

// logic
// Brute force
// find all the substrings -> then maximum consecutive ones from them
// T.C -> >= O(n*n)
// S.C -> O(1)

// Optimal Solution 
// -> Sliding window
// have consecutive no: of one's or not and I can bear K 0's in my window.
// Logic ?
// l = 0;
// r = 0; -> increment by 1 in every iteration
// count = 0; -> no: of zeroes

// while (count > k){
//     if (nums[l] == 0) count--;
//     l++;
// }

// maxi = max(maxi, r - l + 1);


// return maxi;

// T.C -> O(n) -> work properly
// S.C -> O(1)

// edge cases
// if (n == 1) return nums[]