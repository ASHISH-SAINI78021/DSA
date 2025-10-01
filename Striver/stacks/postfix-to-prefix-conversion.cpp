// User function Template for C++

class Solution {
  public:
    bool isOperator (char ch){
        if (ch == '^' || ch == '*' || ch == '+' || ch == '/' || ch == '-'){
            return true;
        }
        else {
            return false;
        }
    }
    string postToPre(string post_exp) {
        stack<string> st;
        int n = post_exp.length();
        
        for (int i = 0; i < n; i++){
            char ch = post_exp[i];
            
            if (isOperator(ch)){
                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();
                
                string expression = ch + operand2 + operand1;
                
                st.push(expression);
            }
            else {
                st.push(string(1 , ch));
            }
        }
        
        return st.top();
    }
};
