// User function Template for C++

class Solution {
  public:
    const int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        queue<pair<int , int>> q;
        q.push({0 , start}); // {count , start}
        vector<int> dist(mod , 1e9);
        dist[start] = 0;
        
        while (!q.empty()){
            auto front = q.front();
            int count = front.first;
            int node = front.second;
            q.pop();
            
            if (node == end){
                return count % mod;
            }
            
            for (int i = 0; i < arr.size(); i++){
                int cost = (node * arr[i]) % mod;
                if (count + 1 < dist[cost]){
                    dist[cost] = count + 1;
                    q.push({count + 1, cost});
                }
            }
        }
        
        return -1;
    }
};

