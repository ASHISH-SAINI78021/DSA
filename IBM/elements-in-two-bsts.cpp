#include <bits/stdc++.h> 
void inorder(BinaryTreeNode<int>*root, vector<int> &bst){
    // base case
    if (root == NULL) return ;

    // solution for one case
    inorder(root->left, bst);
    bst.push_back(root->data);
    inorder(root->right, bst);
}
vector<int> allElements(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    int i = 0;
    int j = 0;
    int n = bst1.size();
    int m = bst2.size();
    vector<int> ans;
    while (i < n && j < m){
        if (bst1[i] > bst2[j]){
            ans.push_back(bst2[j++]);
        }
        else {
            ans.push_back(bst1[i++]);
        }
    }
    while (i < n) ans.push_back(bst1[i++]);
    while (j < m) ans.push_back(bst2[j++]);

    return ans;
}











