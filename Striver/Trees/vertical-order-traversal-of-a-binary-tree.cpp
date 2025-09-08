class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }

        map<int , map<int , multiset<int>>> mp;
        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0 , 0}});

        while (!q.empty()){
            auto front = q.front();
            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;
            q.pop();

            mp[col][row].insert(node->val);

            if (node->left){
                q.push({node->left , {row + 1 , col - 1}});
            }
            if (node->right){
                q.push({node->right , {row + 1 , col + 1}});
            }
        }

        for (auto it : mp){
            vector<int> vline;
            for (auto i : it.second){
                for (auto j : i.second){
                    vline.push_back(j);
                }
            }
            ans.push_back(vline);
        }


        return ans;
    }
};