class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return ans; // early exit

        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        int level = 1;
        int minLevel = INT_MAX;
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            usedOnLevel.clear();

            for (int i = 0; i < size; i++) {
                vector<string> path = q.front(); q.pop();
                string word = path.back();

                if (word == endWord) {
                    if (!found) {
                        minLevel = path.size();
                        found = true;
                    }
                    if (path.size() == minLevel) {
                        ans.push_back(path);
                    }
                    continue;
                }

                for (int j = 0; j < word.length(); j++) {
                    string temp = word;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[j] = ch;
                        if (st.find(temp) != st.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            q.push(newPath);
                            usedOnLevel.push_back(temp);
                        }
                    }
                }
            }

            
            for (auto& w : usedOnLevel)
                st.erase(w);

            if (found) break; 
        }

        return ans;
    }
};
