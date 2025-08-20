#include <bits/stdc++.h>
void solve(BinaryTreeNode<int> *root, int maxi, int mini, int &ans){
    // base case
    if (root == NULL) return ;

    // solution for one case
    maxi = max(maxi, root->data);
    mini = min(mini, root->data);
    ans = max({ans, abs(maxi - root->data), abs(root->data - mini)});
    solve(root->left, maxi, mini, ans);
    solve(root->right, maxi, mini, ans);
} 
int maxAncestorDiff(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;
    int parent = 0;
    int maxi = 0;
    int mini = INT_MAX;
    int ans = 0;
    solve(root, maxi, mini, ans);
    return ans;
}