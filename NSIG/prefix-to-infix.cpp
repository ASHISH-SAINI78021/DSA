// User function Template for C++

class Solution {
  public:
    bool isOperator(char target){
        if (target == '*' || target == '/' || target == '+' || target == '-' || target == '^'){
            return true;
        }
        
        return false;
    }
    string preToInfix(string s) {
        int n = s.length();
        stack<string> st;
        for (int i = n - 1; i >= 0; i--){
            char ch = s[i];
            if (isOperator(ch)){
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string result = "(" + op1 + ch + op2 + ")";
                st.push(result);
            }
            else {
                st.push(string(1, ch));
            }
        }
        
        
        return st.top();
    }
};



// s = *-A/BC-/AKL

// Logic
// step1:- start from the end
// step2:- keep traversing until you find an operator and while keeping pushing the elements into the stack
// step3:- pop two elements and add an operator b/w them with parenthesis and push it into the stack
// step4:- repeat the process