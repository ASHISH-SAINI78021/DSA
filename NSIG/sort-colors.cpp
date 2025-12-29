class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high){
            if (nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if (nums[mid] == 1) mid++;
            else {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
        }
    }
};


// Brute force
// return its sorted order
// first inplace mergesort
// T.C -> O(nlogn)
// S.C -> O(1)

// Better Approach
// count0
// count1 
// count2
// count0, count1, count2
// T.C -> O(n)
// S.C -> O(n)  -> Rejected Solution


// Optimal Solution
// Dutch Flag Algorithm
// mid -> 1
// low -> 0
// high -> 2

// low = 0-> index
// mid = 0-> index
// high = n - 1 -> index

// while mid <= high
//     if (nums[mid] == 2) 
//         swap(nums[mid], nums[low]);
//         high--;
//     else if (nums[mid] == 1) mid++;
//     else 
//         swap(nums[mid], nums[low]);
//         mid++;
//         low++;