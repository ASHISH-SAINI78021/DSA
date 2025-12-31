class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int n = fruits.size();
        unordered_map<int, int> mp; 
        int l = 0;
        int r = 0;
        int maxi = 0;

        while (r < n){
            mp[s[r]]++;
            while (mp.size() > k){
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            int count = 0;
            for (auto it : mp){
                count += it.second;
            }
            maxi = max(maxi, count);
            r++;
        }

        return maxi;
    }
};


// fruits = 1 2 1 two baskets -> infinite number of fruits -> each basket can hold only a type of fruit 
// start point I can decide but I've to pick exactly one fruit while moving to the right

// Maximum num of fruits ?


// Logic
// k = 2
// fruits = 1 2 3 2 2
// Brute force
// fin
// I'll keep a track of unique elements > 2 then discard
// maximum number of fruits I can hold.

// T.C -> O(n*n)
// S.C -> O(1);


// Optimal Approach
// -> Sliding window -> O(n)
// -> map -> keeps track of number of unique elements -> size upto size 2;
// S.C -> O(1)

// edge cases
// n = 1 -> 