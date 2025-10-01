class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec (char target){
        if (target == '^'){
            return 3;
        }
        else if (target == '*' || target == '/'){
            return 2;
        }
        else if (target == '+' || target == '-'){
            return 1;
        }
        else {
            return -1;
        }
    }
    string infixToPostfix(string s) {
        stack<char> st;
        string result;
        int n = s.length();
        
        for (int i = 0; i < n; i++){
            char ch = s[i];
            
            if (ch == '('){
                st.push(ch);
            }
            else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
                result += ch;
            }
            else if (s[i] == ')'){
                while (st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && 
       ((ch != '^' && prec(ch) <= prec(st.top())) || 
        (ch == '^' && prec(ch) < prec(st.top())))){
    result += st.top();
    st.pop();
}

                st.push(ch);
            }
        }
        
        
        while (!st.empty()){
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};

