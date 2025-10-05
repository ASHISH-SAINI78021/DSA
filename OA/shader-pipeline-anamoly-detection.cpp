#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> duplicateElements(const vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    for (auto it : mp){
        if (it.second > 1) ans.push_back(it.first);
    }

    return ans;
}
int main(){
    vector<int> shader_ids = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = duplicateElements(shader_ids);
    cout << "Duplicate elements : " << " "; 
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}