class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0; int j = 0;
        vector<int> ans;

        while (i < n && j < m){
            if (nums1[i] < nums2[j]){
                ans.push_back(nums1[i++]);
            }
            else {
                ans.push_back(nums2[j++]);
            }
        }
        while (i < n) ans.push_back(nums1[i++]);
        while (j < m) ans.push_back(nums2[j++]);

        int totalSize = ans.size();
        if (totalSize % 2 == 1){
            return (double)ans[totalSize/2];
        }
        else {
            int mid1 = totalSize/2 - 1;
            int mid2 = totalSize/2;
            return (double)((double)ans[mid1] + (double)ans[mid2])/2.0;
        }
    }
};