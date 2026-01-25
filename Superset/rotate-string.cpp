class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.size();
        if (n != m){
            return false;
        }

        s = s + s;

        return s.find(goal) != string::npos;
    }
};

// s = s + s;
// abcdeabcde goal -> will be the substring-> true : false;
// T.C -> O(n)
// S.C -> O(n)