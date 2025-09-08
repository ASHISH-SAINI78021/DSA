class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        bool leftToRight = true;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            deque<int> dq;
            for (int i = 0; i < size; i++){
                auto front = q.front();q.pop();
                if (leftToRight){
                    dq.push_back(front->val);
                }
                else {
                    dq.push_front(front->val);
                }

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            vector<int> result(dq.begin(), dq.end());
            ans.push_back(result);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};