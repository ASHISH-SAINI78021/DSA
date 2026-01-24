class Solution {
public:
    bool isSafe(vector<int> &weights, int wt, int days){
        int n = weights.size();
        int day = 1;
        int load = 0;
        for (int i = 0; i < n; i++){
            if (load + weights[i] <= wt){
                load += weights[i];
            }
            else {
                day++;
                load = weights[i];
            }
        }

        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(weights, mid, days)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};