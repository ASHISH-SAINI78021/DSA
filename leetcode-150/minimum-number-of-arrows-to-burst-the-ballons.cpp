class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        int arrows = 1;

        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int last = points[0][1];
        for (int i = 0; i < n; i++){
            if (last < points[i][0]){
                arrows++;
                last = points[i][1];
            }
        }

        return arrows;
    }
};