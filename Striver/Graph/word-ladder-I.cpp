class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st (wordList.begin(), wordList.end());
        queue<pair<int, string>> q;
        q.push({0, beginWord});

        while (!q.empty()){
            auto front = q.front(); q.pop();
            string word = front.second;
            int steps = front.first;
            if (word == endWord) return steps + 1;
            for (int i = 0; i < word.length(); i++){
                char originalWord = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        q.push({steps + 1, word});
                        st.erase(word);
                    }
                }
                word[i] = originalWord;
            }
        }

        return 0;
    }
};