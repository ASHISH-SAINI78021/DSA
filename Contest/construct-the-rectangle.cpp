class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;
        for (int i = floor(sqrt(area)); i > 0; i--){
            if (area % i == 0){
                ans.push_back(area/i);
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};