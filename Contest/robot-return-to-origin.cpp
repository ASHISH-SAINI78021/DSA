class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        unordered_map<char, pair<int,int>> mp;
        mp['U'] = make_pair(0, 1);
        mp['D'] = make_pair(0, -1);
        mp['L'] = make_pair(-1, 0);
        mp['R'] = make_pair(1, 0);
        int row = 0;
        int col = 0;

        for (int i = 0; i < n; i++){
            row = row + mp[moves[i]].first;
            col = col + mp[moves[i]].second;
        }
        if (row == 0 && col == 0) return true;
        else return false;
    }
};