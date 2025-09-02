
class Solution {
  public:
    void reverseStack(stack<int> &st, vector<int> &arr){
        int n = arr.size();
        for (int i = 0; i < n; i++){
            st.push(arr[i]);
        }
    }
    void solve(stack<int> &st, vector<int> &arr){
        // base case
        if (st.empty()) return ;
        
        // solution for one case
        int element = st.top();st.pop();
        arr.push_back(element);
        solve(st, arr);
    }
    void reverse(stack<int> &st) {
        vector<int> arr;
        solve(st, arr);
        reverseStack(st, arr);
    }
};