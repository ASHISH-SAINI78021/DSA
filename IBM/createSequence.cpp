using ll = long long;
void solve(ll n, ll curr, vector<ll> &ans){
    // base case
    if (curr > n) return ;
    if (curr != 0) ans.push_back(curr);

    // solution for one case
    if (curr*10 + 2 <= n){
        solve(n, curr*10 + 2, ans);
    }
    if (curr*10 + 5 <= n){
        solve(n, curr*10 + 5, ans);
    }
}
vector<long long> createSequence(long long n){
    vector<ll> ans;
    if (n == 0) return ans;
    ll curr = 0;
    solve(n, curr, ans);

    sort(ans.begin(), ans.end());

    return ans;
}