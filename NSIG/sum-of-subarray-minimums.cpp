class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n, -1);
        vector<int> nle(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (!st.empty()) ple[i] = st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nle[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++){
            int left = i - ple[i];
            int right = nle[i] - i;
            long long count = left * right;
            sum = (sum % mod + arr[i] * count) % mod;
        }
        
        return sum;
    }
};


// arr = 3 1 2 4
// Naive Approach
// step1:- find all the subarrays
// step2:- now find the minimum for each
// step3:- simultanesously find the sum and return at the end

// Optimal Approach
// -> for every element, how many sub arrays are there for which this element is minimum
// contribution formula -> what is it ?
// contribution = arr[i] * (number of elements)

// -> two vectors -> Previous Lowest Element and Next smallest element -> why is there a need of this one ?

// -> number of element = left * right
// -> left = it is the number of elements greater than the current element on the left side
// -> right = it is the number of elements greater than or equal to current element



// Check Notes section