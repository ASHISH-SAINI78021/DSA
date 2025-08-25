class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < n; i++){
            pq.push({matrix[i][0], {i, 0}});
        }

        int ans = -1;
        while (k-- && !pq.empty()){
            auto top = pq.top();pq.pop();
            int element = top.first;
            ans = element;
            int i = top.second.first;
            int j = top.second.second;

            if (j + 1 < n){
                pq.push({matrix[i][j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};