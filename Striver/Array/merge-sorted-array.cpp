class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> arr = nums1;

        while (i < m && j < n){
            if (arr[i] <= nums2[j]){
                nums1[k++] = arr[i];
                i++;
            }
            else {
                nums1[k++] = nums2[j];
                j++;
            }
        }


        while (i < m){
            nums1[k++] = arr[i++];
        }

        while (j < n){
            nums1[k++] = nums2[j++];
        }
    }
};