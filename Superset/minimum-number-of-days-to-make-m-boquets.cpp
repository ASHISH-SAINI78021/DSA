class Solution {
public:
    bool isSafe(vector<int> &bloomDay, int mid, int m, int k){
        int n = bloomDay.size();
        int count = 0;
        int flowers = 0;
        for (int i = 0; i < n; i++){
            if (bloomDay[i] <= mid){
                count++;
            }
            else {
                flowers += count/k;
                count = 0;
            }
        }

        flowers += count/k;

        return flowers >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(bloomDay, mid, m, k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};



// m bouquet -> to be made
// 1 bouquet -> can be made using k adjacent flowers
// find the minimum number of days we've to wait to make m bouquets.


// 1 10 3 10 2    m = 3, k = 1
// 1  2 3  4 5

// day1->> x,-,-,-,-
// day2->> x,-,-,-,x
// day3->> x,-,x,-,x

// ans = 3

// logic
// day = 1 -> how many bqs can I make ? => count >= m 
// day = 2
// day = 3