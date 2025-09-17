class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()){
            int size = q.size();
            vector<TreeNode*> temp;
            for (int i = 0; i < size; i++){
                auto front = q.front();q.pop();
                if (level & 1){
                    temp.push_back(front);
                }
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            int i = 0;
            int j = temp.size() - 1;
            while (i < j){
                swap(temp[i]->val, temp[j]->val);
                i++;j--;
            }

            level++;
        }

        return root;
    }
};