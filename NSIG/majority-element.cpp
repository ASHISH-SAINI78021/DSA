class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1;
        int count = 0;

        for (int i = 0; i < n; i++){
            if (count == 0){
                candidate = nums[i];
                count = 1;
            }
            else if (candidate == nums[i]) count++;
            else count--;
        }

        return candidate;
    }
};


// nums = 3 2 3
// n / 2 -> majority elment -> 1
// return -1 -> I must have a majority in an array.

// Brute force
// map -> find frequencies -> if n/2 > -> return element
// T.C -> O(n)
// S.C -> O(1)

// Optimal Approach 
// Boye's moore Algorithm
// candidate = -1;
// count = 0;
// count++ count-- eventually gives the majority element -> what would be the algo to do so ? -> I'll be showing it in a while

// T.C -> O(n)
// S.C -> O(1);