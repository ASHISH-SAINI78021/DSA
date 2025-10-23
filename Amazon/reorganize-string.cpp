class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        string ans = "";
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) mp[s[i]]++;
        using T = pair<int, char>;
        priority_queue<T> pq;
        for (auto it : mp){
            pq.push({it.second, it.first});
        }

        while (pq.size() > 1){
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            ans += top1.second; top1.first--;
            ans += top2.second; top2.first--;

            if (top1.first != 0) pq.push(top1);
            if (top2.first != 0) pq.push(top2);
        }

        if (pq.size() == 1){
            ans += pq.top().second;
            if (pq.top().first != 1) ans = "";
        }

        return ans;
    }
};