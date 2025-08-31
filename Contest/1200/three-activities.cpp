#include <bits/stdc++.h>
using namespace std;
using T = pair<int,int>;
vector<T> solve(vector<int> &nums){
    int n = nums.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        arr[i].first = nums[i];
        arr[i].second = i;
    }
    sort(arr.rbegin(), arr.rend());
    vector<pair<int,int>> temp;
    for (int i = 0; i < 3; i++){
        temp.push_back(arr[i]);
    }

    return temp;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        
        vector<T> maxa = solve(a);
        vector<T> maxb = solve(b);
        vector<T> maxc = solve(c);
        int maxi = 0;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    int a = maxa[i].second;
                    int b = maxb[j].second;
                    int c = maxc[k].second;
                    if (a != b && b != c && c != a){
                        maxi = max(maxi, maxa[i].first + maxb[j].first + maxc[k].first);
                    }
                }
            }
        }

        cout << maxi << endl;
    }
    return 0;
}