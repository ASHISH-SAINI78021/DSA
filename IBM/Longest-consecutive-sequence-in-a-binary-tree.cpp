#include <bits/stdc++.h>
using namespace std; 
void solve(BinaryTreeNode<int> *root, int expected, int len, int &maxi){
    // base case
    if (root == NULL) return ;
    if (expected == root->data){
        len++;
    }
    else {
        len = 1;
    }
    maxi = max(maxi, len);

    // solution for one case
    solve(root->left, root->data + 1, len, maxi);
    solve(root->right, root->data + 1, len, maxi);
}
int maxPath(BinaryTreeNode<int> *root) {
    if (root == NULL) return -1;
    int maxi = 1;
    int curr = 0;
    int expected = root->data;
    solve(root, curr, expected, maxi);

    return maxi;
}