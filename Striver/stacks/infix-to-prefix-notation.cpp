class Solution {
  public:
    int prec(char ch){
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }
    bool isOperator(char ch){
        if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^') return true;
        else return false;
    }
    string solve(string &s){
        int n = s.size();
        stack<string> st;
        for (int i = 0; i < n; i++){
            char ch = s[i];
            if (isOperator(ch)){
                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();
                string result = ch + operand2 + operand1;
                st.push(result);
            }
            else st.push(string(1, ch));
        }
        
        return st.top();
    }
    string infixToPrefix(string &s) {
       int n = s.length();
       stack<char> st;
       string result;
       for (int i = 0; i < n; i++){
           char ch = s[i];
           if (ch == '('){
               st.push(ch);
           } 
           else if (isalnum(ch)){
               result += ch;
           }
           else if (!st.empty() && ch == ')'){
               while (!st.empty() && st.top() != '('){
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
           result += st.top(); st.pop();
       }
       string ans = solve(result);
       
       return ans;
    }
};
