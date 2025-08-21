#include <bits/stdc++.h> 
string isPossible(string a, string b, int n, int k)
{
    string yes = "Yes";
    string no = "No";
    if (a.size() != b.size()) return no;
    int freq1[26] = {0};
    int freq2[26] = {0};
    for (int i = 0; i < n; i++){
        freq1[a[i] - 'a']++;
        freq2[b[i] - 'a']++;
    }

    for (int i = 0; i < 25; i++){
        if (freq1[i] < freq2[i]) return no;
        int extra = freq1[i] - freq2[i];
        if (extra % k != 0) return no;
        freq1[i + 1] += extra;
    }

    return freq1[25] == freq2[25] ? yes : no;
}