class Solution {
public:
    vector<int> solve(int n){
        vector<int> arr;
        while (n > 0){
            int rem = n % 10;
            arr.push_back(rem);
            n = n/10;
        }
        reverse(arr.begin(), arr.end());
        
        return arr;
    }
    int maximum69Number (int num) {
        vector<int> arr = solve(num);
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == 6){
                arr[i] = 9; break;
            }
        }

        int n = 0;
        for (int i = 0; i < arr.size(); i++) n = n*10 + arr[i];

        return n;
    }
};