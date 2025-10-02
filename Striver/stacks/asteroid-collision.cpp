class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < n; i++){
            bool destroyed = false;
            while (!st.empty() && (arr[i] < 0 && st.top() > 0)){
                int element = arr[i];
                if (abs(element) > st.top()){
                    st.pop();
                    continue ;
                }
                else if (abs(element) == st.top()){
                    destroyed = true;
                    st.pop();
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed){
                st.push(arr[i]);
            }
        }

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }  

        reverse(ans.begin(), ans.end());      

        return ans;
    }
};