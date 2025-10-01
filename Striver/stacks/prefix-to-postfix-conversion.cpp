class Solution {
  public:
    bool isOperator(char ch){
        if (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '^') return true;
        else return false;
    }
    string preToPost(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = n - 1; i >= 0; i--){
            char ch = s[i];
            if (isOperator(ch)){
                string operand1 = st.top();st.pop();
                string operand2 = st.top();st.pop();
                string result = operand1 + operand2 + ch;
                st.push(result);
            }
            else {
                st.push(string(1, ch));
            }
        }
        
        string result = st.top();
        return result;
    }
};