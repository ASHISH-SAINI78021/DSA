class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int i = 0;
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        while (i < n & j < m){
            if (s[j] >= g[i]){
                count++;
                i++; j++;
            }
            else if (g[i] > s[j]){
                j++;
            }
            else i++;
        }

        return count;
    }
};