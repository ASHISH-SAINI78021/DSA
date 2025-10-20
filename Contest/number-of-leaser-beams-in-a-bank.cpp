class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = -1;
        int sum = 0;
        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < bank[i].size(); j++){
                if (bank[i][j] == '1') count++;
            }
            if (prev == -1) prev = count;
            else if (prev != -1 && count != 0) {
                sum += count * prev;
                // cout << "sum : " << sum << " ";
                prev = count;
            }
        }

        return sum
    }
};