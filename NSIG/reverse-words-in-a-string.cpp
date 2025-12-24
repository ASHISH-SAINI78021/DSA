class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        stack<string> st;

        string temp = "";
        for (int i = 0; i < n; i++){
            if (s[i] != ' '){
                temp += s[i];
            }
            else {
                if (!temp.empty()) st.push(temp);
                temp.clear();
            }
        }


        if (!temp.empty()) st.push(temp);
        while (!st.empty()){
            ans += st.top(); st.pop();
            ans += " ";
        }

        if (!ans.empty()) ans.pop_back();
        return ans;
    }
};


// s = the sky is blue
// o/p = blue is sky the

// -> intuition -> it is like reversing the characters -> for this we've to store words and reverse the all words 
// -> I can use stack here -> it always return the reverse order
// -> just push word into the stack