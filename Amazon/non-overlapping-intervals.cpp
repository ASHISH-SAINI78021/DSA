class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int prevEnd = INT_MIN;
        int removeCount = 0;
        for (int i = 0; i < n; i++){
            if (prevEnd <= intervals[i][0]){
                prevEnd = intervals[i][1];
            }
            else {
                removeCount++;
            }
        }

        return removeCount;
    }
};