class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);

        if (gasSum < costSum) return -1;

        int start = 0;
        int currgas = 0;
        for (int i = 0; i < n; i++){
            currgas += gas[i] - cost[i];
            if (currgas < 0){
                start = i + 1;
                currgas = 0;
            }
        }

        if (currgas < 0) return -1;
        return start;
    }
};