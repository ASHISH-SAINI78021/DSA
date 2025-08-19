#include <bits/stdc++.h> 
using namespace std;
bool isValid(BinaryTreeNode<int> *root, int low, int high, int &count){
    // base case
    if (root == NULL) return true;

    // solution for one case
    // bool curr = isValid(root, low, high, count);
    bool ansleft = isValid(root->left, low, high, count);
    bool ansright = isValid(root->right, low, high, count);
    bool currValid = (root->data >= low && root->data <= high);
    if (ansleft && ansright && currValid){
        count++;
        return true;
    }

    return false;
}
int getCount(BinaryTreeNode<int> *root, int low, int high) 
{
    if (root == NULL) return 0;
    int count = 0;
    isValid(root, low, high, count);

    return count;
}