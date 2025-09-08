class Solution {
  public:
    void solve(Node* root, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if (root == NULL){
            return ;
        }
        if (root->left == NULL && root->right == NULL){
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }
        
        // solution for one case
        temp.push_back(root->data);
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, temp, ans);
        
        return ans;
    }
};