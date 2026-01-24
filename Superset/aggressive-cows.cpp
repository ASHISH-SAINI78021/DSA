class Solution {
  public:
    bool isSafe(vector<int> &stalls, int dis, int k){
        int n = stalls.size();
        int count = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++){
            if (stalls[i] - last >= dis){
                count++;
                last = stalls[i];
            }
        }
        
        return count >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int start = 1;
        int end = stalls[n - 1];
        int ans = -1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(stalls, mid, k)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};







// stalls = 1 2 4 8 9   k = 3

// dis = 1 -> how many aggressive cow can reside their ? - O(n)
// dis = 2 -> count >= k -> minimum -> break; because I'm checking montonically
// i.e 1 2 3 4 5....... max_element -> B.S -> O(logn)

// T.C -> O(n*logn)
// S.C -> O(1)