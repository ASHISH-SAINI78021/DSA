class Solution {
public:
    bool solve(vector<int> &piles, int h, int k){
        int n = piles.size();
        long long totalHrs = 0;

        for (int i = 0; i < n; i++){
            totalHrs += (piles[i] + k - 1)/k;
        }

        return totalHrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = n;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (solve(piles, h, mid)){
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