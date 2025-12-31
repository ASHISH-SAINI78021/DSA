class Solution {
  public:
    void leftTraversal(Node* root, vector<int> &ans){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL) return ;
        ans.push_back(root->data);
        if (root->left){
            leftTraversal(root->left, ans);
        }
        else leftTraversal(root->right, ans);
    }
    void leafNode(Node* root, vector<int> &ans){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return ;
        }
        leafNode(root->left, ans);
        leafNode(root->right, ans);
    }
    void rightTraversal(Node* root, vector<int> &ans){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL) return ;
        if (root->right){
            rightTraversal(root->right, ans);
        }
        else rightTraversal(root->left, ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        if (root == NULL) return {};
        vector<int> ans;
        ans.push_back(root->data);
        if (root->left == NULL && root->right == NULL){
            return ans;
        }
        if (root->left){
            leftTraversal(root->left, ans);
        }
        leafNode(root, ans);
        if (root->right){
            rightTraversal(root->right, ans);
        }
        
        
        return ans;
    }
};