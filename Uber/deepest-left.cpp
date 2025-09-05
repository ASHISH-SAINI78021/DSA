#include <bits/stdc++.h>
using namespace std;
void solve(BinaryTreeNode<int>* root, int level, bool isLeft, int &maxDepth, int &ans) {
    // base case
    if (root == NULL) return ;
    if (isLeft && root->left == NULL && root->right == NULL){
        if (level > maxDepth){
            maxDepth = level;
            ans = root->data;
        }
        else if (level == maxDepth){
            ans = max(ans, root->data);
        }
    }

    // solution for one case
    solve(root->left, level + 1, true, maxDepth, ans);
    solve(root->right, level + 1, false, maxDepth, ans);
}

int deepestLeftLeafNode(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;
    int ans = 0;
    int maxDepth = -1;
    solve(root, 0, false, maxDepth, ans);
    return ans;
}
