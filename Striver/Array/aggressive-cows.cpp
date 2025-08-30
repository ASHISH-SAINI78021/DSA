class Solution {
public:
    bool solve(vector<int> &stalls, int distance, int k) {
        int n = stalls.size();
        int cows = 1;                // place first cow at stalls[0]
        int prevStall = stalls[0];

        for (int i = 1; i < n; i++) {
            int currentStall = stalls[i];
            if (currentStall - prevStall >= distance) {
                cows++;
                prevStall = currentStall;
            }
        }
        return cows >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int start = 1;
        int end = stalls[n - 1] - stalls[0];
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (solve(stalls, mid, k)) {
                ans = mid;           // possible, try bigger distance
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
