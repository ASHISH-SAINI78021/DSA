class Solution {
public:
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int inorderStart, int inorderEnd, int &preIndex, unordered_map<int, int> &mp){
        // base case
        if (inorderStart > inorderEnd || preIndex > preorder.size()) return NULL;

        // solution for one case
        int element = preorder[preIndex++];
        int pos = mp[element];
        TreeNode* root = new TreeNode(element);
        root->left = solve(preorder, inorder, inorderStart, pos - 1, preIndex, mp);
        root->right = solve(preorder, inorder, pos + 1, inorderEnd, preIndex, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int inorderStart = 0;
        int inorderEnd = n - 1;
        int preIndex = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, inorder, inorderStart, inorderEnd, preIndex, mp);

        return root;
    }
};