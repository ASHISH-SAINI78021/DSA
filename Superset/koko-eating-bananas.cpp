class Solution {
public:
    bool isSafe(vector<int> &piles, int mid, int h){
        int n = piles.size();
        long long hrs = 0;
        for (int i = 0; i < n; i++){
            hrs += 1LL*(piles[i] + mid - 1)/mid;
        }

        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(piles, mid, h)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};

// 3 6 7 11     h = 8
// k -> koko can eat all the bananas with minimum speed of eating.

// I have to return the minimum speed of eating such that koko can eat all bananas in h hrs.

// k = 1 per hour -> she would be able to eat all the bananas
// k = 2 .... 3 4 5 6..... upto koko can eat max_pile -> banana
// due to this monotonic behaviour------ I can use Binary search here
// I've to calculate the lower bound;