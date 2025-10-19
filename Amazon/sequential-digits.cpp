class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i <= 9; i++) q.push(i);
        while (!q.empty()){
            auto front = q.front(); q.pop();
            if (front >= low && front <= high) ans.push_back(front);
            if (front > high) continue ;
            int lastDigit = front % 10;
            if (lastDigit < 9){
                int nextNum = front*10 + lastDigit + 1;
                q.push(nextNum);
            }
        }

        return ans;
    }
};