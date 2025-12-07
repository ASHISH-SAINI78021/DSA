class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int words = wordList.size();
        int n = beginWord.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;
        using T = pair<int , string>;
        queue<T> q;
        q.push({1, beginWord});
        if (st.find(beginWord) != st.end()) st.erase(beginWord);
        int maxSteps = 0;

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int steps = front.first;
            string word = front.second;
            maxSteps = max(steps, maxSteps);
            if (word == endWord) return steps;
            for (int i = 0; i < n; i++){
                char target = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        q.push({steps + 1, word}); 
                        st.erase(word);
                    }
                }
                word[i] = target;
            }
        }

        return 0;
    }
};