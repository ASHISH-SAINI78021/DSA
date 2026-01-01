class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        using T = pair<TreeNode*, int>;
        queue<T> q;
        q.push({root, 0});
        int maxi = 0;

        while (!q.empty()){
            int size = q.size();
            int first;
            int last;
            for (int i = 0; i < size; i++){
                auto front = q.front(); q.pop();
                auto node = front.first;
                int currIndex = front.second;
                if (i == 0){
                    first = currIndex;
                }
                if (i == size - 1) last = currIndex;

                if (node->left){
                    q.push({node->left, 2*currIndex});
                }
                if (node->right){
                    q.push({node->right, 2*currIndex + 1});
                }
            }

            maxi = max(maxi, last - first + 1);
        }

        return maxi;
    }
};