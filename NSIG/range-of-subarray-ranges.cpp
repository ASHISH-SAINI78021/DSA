class Solution {
public:
    void clearStack(stack<int> &st){
        while (!st.empty()) st.pop();
    }
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n, -1);
        vector<int> nle(n, n);
        vector<int> pge(n, -1);
        vector<int> nge(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (!st.empty()) ple[i] = st.top();
            st.push(i);
        }
        clearStack(st);
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nle[i] = st.top();
            st.push(i);
        }
        clearStack(st);
        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }
        clearStack(st);
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++){
            long long minCount = (long long)(i - ple[i]) * (nle[i] - i);
            long long maxCount = (long long)(i - pge[i]) * (nge[i] - i);

            ans += (long long)arr[i] * (maxCount - minCount);
        }

        return ans;
    }
};