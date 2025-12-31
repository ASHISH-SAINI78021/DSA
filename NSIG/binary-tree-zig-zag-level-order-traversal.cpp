class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = false;

        while (!q.empty()){
            int size = q.size();
            deque<int> dq;
            for (int i = 0; i < size; i++){
                auto front = q.front(); q.pop();
                if (leftToRight){
                    dq.push_front(front->val);
                }
                else {
                    dq.push_back(front->val);
                }

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            vector<int> temp(dq.begin(), dq.end());
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }


        return ans;
    }
};


// T.C -> O(n)
// S.C -> O(n)