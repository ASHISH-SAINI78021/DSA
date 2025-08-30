class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> ans;
        int n1 = a.size();
        int n2 = b.size();
        
        int i = 0;
        int j = 0;
        
        while (i < n1 && j < n2){
            if (a[i] <= b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while (i < n1){
            ans.push_back(a[i]);
            i++;
        }
        
        while (j < n2){
            ans.push_back(b[j]);
            j++;
        }
        
        return ans[k - 1];
    }
};
