class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++){
            water += max(0, min(prefix[i], suffix[i]) - height[i]);
        }

        return water;
    }
};

// height = 0 1 0 2 1 0 1 3 2 1 2 1
// ans -> 6
// Approach
// for each tower I'm Calculating how much water It can accomodate and width of the every tower is 1 unit
// so water at index i
// i.e water += max(0, min(minHeight[i], maxHeight[i]) - height[i]);
// naive approach
// T.C -> O(n*n)
// S.C -> O(1)

// Better Approach
// prefix, suffix arrays for accounting minimum and maximum. 
// T.C -> O(n)
// S.C -> O(n)
