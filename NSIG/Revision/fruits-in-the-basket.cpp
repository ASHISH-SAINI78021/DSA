class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int k = 2;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while (r < n){
            mp[fruits[r]]++;
            while (mp.size() > k){
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) mp.erase(fruits[l]);
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


// fruits = 1 2 1
// 1 2 1 -> 3 

// 0 1 2 2
// 0 1 -> 2
// 1 2 2 -> 3