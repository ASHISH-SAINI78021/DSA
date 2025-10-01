// User function Template for C++

class Solution {
  public:
    bool isOperator(char ch){
        if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^') return true;
        return false;
    }
    string preToInfix(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = n - 1; i >= 0; i--){
            char ch = s[i];
            if (isOperator(ch)){
                string operand1 = st.top();st.pop();
                string operand2 = st.top(); st.pop();
                string result = "(" + operand1 + ch + operand2 + ")";
                st.push(result);
            }
            else {
                string str; str.push_back(ch);
                st.push(str);
            }
        }
        
        string result = st.top();
        
        return result;
    }
};