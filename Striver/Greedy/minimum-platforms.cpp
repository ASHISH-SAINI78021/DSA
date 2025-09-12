class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int maxPlatforms = 0;
        int platforms = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n){
            if (arr[i] <= dep[j]){
                platforms++;
                i++;
                maxPlatforms = max(maxPlatforms, platforms);
            }
            else {
                j++;
                platforms--;
            }
        }
        
        return maxPlatforms;
    }
};
