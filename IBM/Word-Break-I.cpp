#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void backtrack(string &s, unordered_set<string> &st, int index, string temp, vector<string> &ans){
  // base case
  if (index >= s.size()){
    temp.pop_back();
    ans.push_back(temp);
    return ;
  }
  
  // solution for one case
  string word;
  for (int i = index; i < s.size(); i++){
    word.push_back(s[i]);
    if (st.find(word) != st.end()){
      backtrack(s, st, i + 1, temp + word + " ", ans);
    }
  }
}
int main() 
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++){
      cin >> dict[i];
    }
    string s;
    cin >> s;
    unordered_set<string> st(dict.begin(), dict.end());
    vector<string> ans;
    string temp;
    int index = 0;
    backtrack(s, st, index, temp, ans);
    if (ans.empty()) return -1;
    else {
      for (auto it : ans) cout << it << endl;
    }
    return 0;
}


// test cases
// 6
// god
// is
// now
// no
// where
// here
// godisnowherenowhere