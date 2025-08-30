class Solution {
public:
    bool solve(vector<int> &bloomDay, int m, int k, int days){
        int n = bloomDay.size();
        int count = 0;
        int b = 0;
        
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) {
                count++;
                if (count == k) { 
                    b++; 
                    count = 0; 
                }
            } else {
                count = 0; // reset because not consecutive
            }
        }

        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start = 1;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        if (m*1ll*k*1ll > n){
            return -1;
        }


        while (start <= end){
            int mid = start + (end - start)/2;
            if (solve(bloomDay, m, k , mid)){
                ans = mid; 
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};