class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });
        cout << "Arr : " << endl;
        for (auto it : arr){
            cout << it[0] << " " << it[1] << endl;
        }

        int ans = 0;
        int count = 0;
        cout << "Arr ends here ...." << endl;
        for (int i = 0; i < n; i++){
            count += arr[i][0];
            if (count <= truckSize){
                ans += arr[i][0] * arr[i][1];
                cout << "count: " << count << "  ";
                cout << "ans: " << ans << "  ";
            }
            else {
                ans += abs(truckSize - count + arr[i][0])*arr[i][1];
                cout << "count: " << count << "  ";
                cout << "ans: " << ans << "  ";
                break ;
            }
        }

        return ans;
    }
};