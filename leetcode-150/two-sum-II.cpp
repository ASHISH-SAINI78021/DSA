class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;
        while (i < j){
            int sum = numbers[i] + numbers[j];
            if (target == sum){
                return {i + 1, j + 1};
            }
            else if (target < sum){
                j--;
            }
            else {
                i++;
            }
        }

        return {-1, -1};
    }
};