class Solution {
public:
    bool isSafe(vector<int> &quantities, int k, int stores){
        int n = quantities.size();
        int total = 0;
        for (int i = 0; i < n; i++){
            total += (quantities[i] + k - 1)/k;
        }

        return total <= stores;
    }
    int minimizedMaximum(int k, vector<int>& quantities) {
        int n = quantities.size();
        int ans = 0;
        int start = 1; int end = *max_element(quantities.begin(), quantities.end());
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(quantities, mid, k)){
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};