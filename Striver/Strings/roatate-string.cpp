class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if (n != m) return false;

        int startingIndex = -1;
        for (int i = 0; i < n; i++){
            if (s[0] == goal[i]){
                startingIndex = i;
                string temp = goal + goal.substr(0, startingIndex);
                if (s == temp.substr(startingIndex)) return true;
            }
        }

        return false;
    }
};