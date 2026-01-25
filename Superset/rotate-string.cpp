class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if (n != m) return false;

        for (int i = 0; i < n; i++){
            if (s[i] == goal[0]){
                string temp = s.substr(i) + s.substr(0, i);
                if (temp == goal) return true;
            }
        }

        return false;
    }
};


// s = abcde   goal = cdeab
// ab + cde == s ? -> true else return false;


// T.C -> O(n*n)
// S.C -> O(n)