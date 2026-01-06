class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        TreeNode* temp = root;

        while (temp != NULL){
            if (temp->left == NULL){
                ans.push_back(temp->val);
                temp = temp->right;
            }
            else {
                TreeNode* pred = temp->left;
                while (pred->right != NULL && pred->right != temp){
                    pred = pred->right;
                }
                
                if (pred->right == NULL){
                    pred->right = temp;
                    temp = temp->left;
                }
                else {
                    pred->right = NULL;
                    ans.push_back(temp->val);
                    temp = temp->right;
                }
            }
        }

        return ans;
    }
};


// We have to print inorder traversal using O(1) space
// Morris Traversal
// -> We have to modify the tree
// -> level order traversal
// -> if (temp->left == NULL) ans.push_back(temp->val) temp = temp->right;
// -> else 
//     now find the inorder predecessor

//     if (pred->right == NULL) pred->right = temp; temp = temp->left;
//     else 
//         pred->right = NULL;
//         ans.push_back(temp->val)
//         temp = temp->right;


// T.C -> O(n)
// S.C -> O(1)