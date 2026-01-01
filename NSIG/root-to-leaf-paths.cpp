class Solution {
  public:
    void solve(Node* root, vector<int> temp, vector<vector<int>> &ans){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL){
            temp.push_back(root->data);
            ans.push_back(temp);
            return ;
        }
        temp.push_back(root->data);
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<int> temp;
        solve(root, temp, ans);
        
        return ans;
    }
};

// 1 2 4 
// 1 2 5
// 1 3

// T.C -> O(n)
// S.C -> O(max(number of total paths, n))