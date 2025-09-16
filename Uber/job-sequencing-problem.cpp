class Node {
    public:
        int id;
        int dead;
        int profit;
        Node(int id, int dead, int profit){
            this->id = id;
            this->dead = dead;
            this->profit = profit;
        }
};
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int numberOfJobs = 0;
        int maximumProfit = 0;
        vector<Node> jobs;
        for (int i = 0; i < n; i++){
            jobs.push_back({i + 1, deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), [](auto a, auto b){
            return a.profit > b.profit;
        });
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline + 1, -1);
        for (int i = 0; i < n; i++){
            for (int j = jobs[i].dead; j > 0; j--){
                if (slots[j] == -1){
                    numberOfJobs++;
                    maximumProfit += jobs[i].profit;
                    slots[j] = jobs[i].id;
                    break;
                }
            }
        }
        
        return {numberOfJobs, maximumProfit};
    }
};