class Solution {
  public:
    int prec(char &target){
        if (target == '^') return 3;
        else if (target == '*' || target == '/') return 2;
        else if (target == '+' || target == '-') return 1;
        else return 0;
    }
    string infixToPostfix(string& s) {
        int n = s.length();
        string result = "";
        if (n == 1 || n == 2) return s;
        stack<char> st;
        for (int i = 0; i < n; i++){
            char ch = s[i];
            if (isalnum(ch)){
                result += ch;
            }
            else if (ch == '('){
                st.push(ch);
            }
            else if (ch == ')'){
                while (!st.empty() && st.top() != '('){
                    result += st.top();st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && 
      (prec(ch) < prec(st.top()) || 
      (prec(ch) == prec(st.top()) && ch != '^'))) {
    result += st.top();
    st.pop();
}

                st.push(ch);
            }
        }
        
        while (!st.empty()){
            result += st.top(); st.pop();
        }
        
        return result;
    }
};





// s = a*(b+c)/d
// ans -> abc+*d/

// I've operators b/w the operands.....
// operators should be after the operands...... for doing this I can use stack []

// Logic
// step1:- isalnum(ch) -> push it into the result
// step2:- ( -> push it into the stack
// step3:- */-+^ -> push it into the stack
// step4:- ) -> pop all the elements and push them int to the result until you find (
// step5:- after performing step4 pop the last element
// step6:- pop all the operators into the string result.
