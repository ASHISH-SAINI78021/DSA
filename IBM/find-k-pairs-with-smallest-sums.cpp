class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < n && i < k; i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- && !pq.empty()){
            auto top = pq.top();pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < m){
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};