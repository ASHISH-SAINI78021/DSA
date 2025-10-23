class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if (n == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < n; i++){
            if (end >= intervals[i][0]){
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
            else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};