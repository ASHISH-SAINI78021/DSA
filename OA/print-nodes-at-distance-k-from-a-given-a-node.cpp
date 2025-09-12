#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = right = NULL;
    }
};

void solve(BinaryTreeNode<int>* root,
           unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent,
           unordered_map<BinaryTreeNode<int>*, bool>& visited,
           vector<int>& ans, int k) {

    if (root == NULL || visited[root]) return;

    if (k == 0) {
        ans.push_back(root->data);
        return;
    }

    visited[root] = true;

    solve(root->left, parent, visited, ans, k - 1);
    solve(root->right, parent, visited, ans, k - 1);
    solve(parent[root], parent, visited, ans, k - 1);
}

vector<int> printNodesAtDistanceK(BinaryTreeNode<int>* root,
                                  BinaryTreeNode<int>* target, int k) {
    vector<int> ans;
    if (!root) return ans;

    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
    unordered_map<BinaryTreeNode<int>*, bool> visited;

    // Build parent map
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    parent[root] = NULL;

    while (!q.empty()) {
        auto front = q.front(); q.pop();
        if (front->left) {
            parent[front->left] = front;
            q.push(front->left);
        }
        if (front->right) {
            parent[front->right] = front;
            q.push(front->right);
        }
    }

    solve(target, parent, visited, ans, k);
    return ans;
}

int main() {
    // Example usage:
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    vector<int> result = printNodesAtDistanceK(root, root->left, 2);
    for (int x : result) cout << x << " ";
    return 0;
}
