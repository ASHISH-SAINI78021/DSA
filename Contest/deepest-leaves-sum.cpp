class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()){
            int size = q.size();
            sum = 0;
            for (int i = 0; i < size; i++){
                auto front = q.front();q.pop();
                sum += front->val;
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return sum;
    }
};