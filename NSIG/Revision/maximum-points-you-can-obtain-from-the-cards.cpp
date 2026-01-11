class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxi = 0;
        int sum = 0;

        for (int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        maxi = max(maxi, sum);
        for (int i = 0; i < k; i++){
            sum = sum - cardPoints[k - i - 1] + cardPoints[n - 1 - i];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};