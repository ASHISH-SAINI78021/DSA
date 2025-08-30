class Solution {
public:
    bool solve(vector<int> &weights , int wt , int days){
        int n = weights.size();
        int load = 0;
        int count = 1;
        
        for (int i = 0; i < n; i++){
            if (load + weights[i] > wt ){
                count++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }

        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = *max_element(weights.begin() , weights.end());
        int sum = accumulate(weights.begin() , weights.end() , 0);
        int ans = -1;

        int s = maxi;
        int e = sum;
        while (s <= e){
            int mid = s + (e - s)/2;
            if (solve(weights , mid , days)){
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};