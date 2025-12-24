// User function Template for C++

class Solution {
  public:
    bool isOperator(char &target){
        if (target == '^' || target == '*' || target == '/' || target == '+' || target == '-') return true;
        return false;
    }
    string preToPost(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = n - 1; i >= 0; i--){
            char ch = s[i];
            if (isOperator(ch)){
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string result = op1 + op2 + ch;
                st.push(result);
            }
            else {
                st.push(string(1, ch));
            }
        }
        
        return st.top();
    }
};