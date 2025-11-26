class Solution {
public:
    void merge(vector<int>& ans, int m, vector<int>& nums2, int n) {
        vector<int> nums1;
        int k = 0;
        for (int i = 0; i < m; i++){
            nums1.push_back(ans[i]);
        }

        int i = 0; int j = 0;
        while (i < m && j < n){
            if (nums1[i] > nums2[j]){
                ans[k++] = nums2[j++];
            }
            else {
                ans[k++] = nums1[i++];
            }
        }

        while (i < m){
            ans[k++] = nums1[i++];
        }
        while (j < n){
            ans[k++] = nums2[j++];
        }
    }
};