class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({start[i], end[i]});
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        int count = 1;
        int lastIndex = arr[0].second;
        for (int i = 1; i < n; i++){
            if (arr[i].first > lastIndex){
                count++;
                lastIndex = arr[i].second;
            }
        }
        
        return count;
    }
};