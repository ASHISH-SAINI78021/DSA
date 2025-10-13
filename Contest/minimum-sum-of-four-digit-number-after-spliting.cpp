class Solution {
public:
    vector<int> solve(int num){
        vector<int> arr;
        while (num > 0){
            int rem = num % 10;
            arr.push_back(rem);
            num = num / 10;
        }
        sort(arr.begin(), arr.end());

        return arr;
    }
    int minimumSum(int num) {
        vector<int> arr = solve(num);
        
        return arr[0]*10 + arr[3] + arr[1]*10 + arr[2];
    }
};