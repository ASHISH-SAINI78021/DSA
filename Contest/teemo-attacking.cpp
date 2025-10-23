class Solution {
public:





    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        vector<vector<int>> intervals;
        for (int i = 0; i < n; i++){
            if (!intervals.empty() && intervals[intervals.size() - 1][1] >= timeSeries[i]){
                intervals[intervals.size() - 1][0] = min(intervals[intervals.size() - 1][0], timeSeries[i]);
                intervals[intervals.size() - 1][1] = max(intervals[intervals.size() - 1][1], timeSeries[i] + duration - 1);
            }
            else {
                intervals.push_back({timeSeries[i], timeSeries[i] + duration - 1});
            }
        }

        int ans = 0;
        for (int i = 0; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            ans += end - start + 1;
        }

        for (auto it : intervals){
            cout << it[0] << " " << it[1] << endl;
        }

        return ans;
    }
};