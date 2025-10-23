class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int arrow = 1;
        int last = points[0][1];
        for (int i = 1; i < n; i++){
            if (points[i][0] > last){
                arrow++;
                last = points[i][1];
            }
        }

        return arrow;
    }
};