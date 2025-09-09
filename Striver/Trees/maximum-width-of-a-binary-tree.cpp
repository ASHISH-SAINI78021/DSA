class Solution {
public:
    const int mod = 1e9 + 7;
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        queue<pair<TreeNode* , unsigned long long>> q;
        q.push(make_pair(root , 0));
        unsigned long long maxi = 0;

        while (!q.empty()){
            int size = q.size();
            unsigned long long last;
            unsigned long long first;
            for (int i = 0; i < size; i++){
                auto temp = q.front();
                q.pop();
                TreeNode* front = temp.first;
                unsigned long long currIndex = temp.second;

                if (i == 0){
                    first = currIndex;
                }
                if (i == size - 1){
                    last = currIndex;
                }

                if (front->left){
                    q.push(make_pair(front->left , 2 * currIndex));
                }
                if (front->right){
                    q.push(make_pair(front->right , 2 * currIndex + 1));
                }
            }

            maxi = max(maxi , last - first + 1);
        }

        return maxi;
    }
};