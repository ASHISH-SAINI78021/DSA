// User function Template for C++

class Solution {
  public:
    bool isOperator(char &target){
        if (target == '^' || target == '*' || target == '/' || target == '+' || target == '-') return true;
        return false;
    }
    string postToPre(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = 0; i < n; i++){
            char ch = s[i];
            if (isOperator(ch)){
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string result = ch + op2 + op1;
                st.push(result);
            }
            else {
                st.push(string(1, ch));
            }
        }
        
        string ans = st.top();
        return ans;
    }
};


