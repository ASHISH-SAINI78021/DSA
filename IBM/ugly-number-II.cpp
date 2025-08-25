class Solution {
public:
    int nthUglyNumber(int n) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        vector<int> primes = {2,3,5};
        unordered_set<ll> st;

        ll curr = 0;
        pq.push(1);
        st.insert(1);
        for (int i = 0; i < n; i++){
            auto top = pq.top(); pq.pop();
            curr = top;
            for (int j = 0; j < 3; j++){
                ll result = primes[j]*curr;
                if (st.find(result) == st.end()){
                    pq.push(result);
                    st.insert(result);
                }
            }
        }

        return curr;
    }
};