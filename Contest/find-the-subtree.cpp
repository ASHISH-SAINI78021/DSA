/*
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
     bool solveHelper(Node* root1, Node* root2){
         // base case
         if (root1 == NULL && root2 != NULL) return false;
         else if (root1 != NULL && root2 == NULL) return true;
         else if (root1 == NULL && root2 == NULL) return true;
         else if (root1->val != root2->val) return false;
         
         // solution for one case
         auto ansleft = solveHelper(root1->left, root2->left);
         auto ansright = solveHelper(root1->right, root2->right);
         
         return ansleft && ansright;
     }
     void solve(Node* root, vector<Node*> &ans, Node* &target){
         // base case 
         if (root == NULL){
             return ;
         }
         if (target->val == root->val){
             ans.push_back(root);
         }
         
         // solution for one case
         solve(root->left, ans, target);
         solve(root->right, ans, target);
     }
     int findSubtree(Node* root1, Node* root2){
        if (root1 == NULL || root2 == NULL) return 0;
        Node* target = root2;
        vector<Node*> ans;
        solve(root1, ans, target);
        for (auto it : ans){
            if (solveHelper(it, root2)) return 1;
        }
        
        return 0;
     }
};
