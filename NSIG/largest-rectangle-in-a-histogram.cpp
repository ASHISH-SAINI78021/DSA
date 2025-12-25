class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ple(n, -1);
        vector<int> nle(n, n);
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) ple[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) nle[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++){
            int width = nle[i] - ple[i] - 1;
            int area = heights[i]*width;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};


// heights = 2 1 5 6 2 3