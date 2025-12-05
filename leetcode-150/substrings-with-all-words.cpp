class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.length();
        int m = words.size();
        int l = words[0].size();
        int totalLen = m*l;
        if (n < totalLen) return {};

        unordered_map<string, int> mp;
        for (auto it : words) mp[it]++;
        for (int i = 0; i < l; i++){
            int left = i;
            int right = i;
            unordered_map<string, int> window;
            int count = 0;
            while (right + l <= n){
                string word = s.substr(right, l);
                right += l;
                if (mp.find(word) == mp.end()){
                    window.clear();
                    left = right;
                    count = 0;
                    continue;
                }
                window[word]++;
                count++;
                while (window[word] > mp[word]){
                    string leftword = s.substr(left, l);
                    window[leftword]--;
                    count--;
                    left += l;
                }

                if (count == m){
                    ans.push_back(left);
                    string leftword = s.substr(left, l);
                    window[leftword]--;
                    count--;
                    left += l;
                }
            }
        }

        return ans;
    }
};