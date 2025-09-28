class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) return 0;
        unordered_map<TreeNode*, TreeNode*> grandParent;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        grandParent[root] = NULL;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto front = q.front(); q.pop();
                if (front->left){
                    parent[front->left] = front;
                    grandParent[front->left] = parent[front];
                    q.push(front->left);
                }
                if (front->right){
                    parent[front->right] = front;
                    grandParent[front->right] = parent[front];
                    q.push(front->right);
                }
            }
        }        

        int sum = 0;
        for (auto it : grandParent){
            if (it.second && it.second->val % 2 == 0){
                sum += it.first->val;
            }
        }

        return sum;
    }
};