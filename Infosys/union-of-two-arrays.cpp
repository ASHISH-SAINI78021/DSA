class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        int i = 0; int j = 0;
        
        while (i < n && j < m){
            int val;
            if (a[i] < b[j]){
                val = a[i++];
            }
            else if (a[i] > b[j]) val = b[j++];
            else {
                val = a[i];
                i++;
                j++;
            }
            
            while (ans.empty() || ans.back() != val) ans.push_back(val);
        }
        
         while (i < n) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }

        while (j < m) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
        
        return ans;
    }
};