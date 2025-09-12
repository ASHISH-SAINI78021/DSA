#include <bits/stdc++.h>
using namespace std;
int minDeletions(string &s, int i, int j){
    // base case

    // solution for one case
    
}
int main(){
    string s;
    cin >> s;
    int i = n - 1; int j = n - 1;
    string reversedString = s;
    reverse(reversedString.begin(), reversedString.end());
    int minimumDeletions = minDeletions(s, reversedString, index);
    cout << minDeletions << endl;

    return 0;
}