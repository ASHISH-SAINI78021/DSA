class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 1) return intervals;

        sort(intervals.begin(), intervals.end());
        int last = intervals[0][1];
        int start = intervals[0][0];
        for (int i = 1; i < n; i++){
            if (intervals[i][0] <= last){
                start = min(start, intervals[i][0]);
                last = max(last, intervals[i][1]);
            }
            else {
                ans.push_back({start, last});
                start = intervals[i][0];
                last = intervals[i][1];
            }
        }

        ans.push_back({start, last});

        return ans;
    }
};