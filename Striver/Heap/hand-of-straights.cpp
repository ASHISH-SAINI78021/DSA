class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if (n % k != 0) return false; 
        map<int, int> mp;

        for (int i = 0; i < n; i++) mp[hand[i]]++;
        while (!mp.empty()){
            int start = mp.begin()->first;
            for (int i = 0; i < k; i++){
                int curr = start + i;
                if (mp[curr] == 0) return false;
                mp[curr]--;
                if (mp[curr] == 0) mp.erase(curr);
            }
        }

        return true;
    }
}; 