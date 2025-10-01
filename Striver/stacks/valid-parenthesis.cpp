class Solution {
public:
    char solve (char &target){
        if (target == ')'){
            return '(';
        }
        else if (target == ']'){
            return '[';
        }
        else {
            return '}';
        }
    }
    bool isValid(string s) {
       int n = s.length();
       stack<int> st;

       for (int i = 0; i < n; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else {
                if (!st.empty()){
                    char element = st.top();
                if (s[i] == ')' && element == '('){
                    st.pop();
                }
                else if (s[i] == '}' && element == '{'){
                    st.pop();
                }
                else if (s[i] == ']' && element == '['){
                    st.pop();
                }
                else {
                    return false;
                }
                }
                else {
                    return false;
                }
                
            }
       } 

       return (st.size()) ? false : true;
    }
};