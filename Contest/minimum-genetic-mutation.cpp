class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st (bank.begin(), bank.end());
        if (st.size() == 0) return -1;
        queue<pair<int, string>> q;
        q.push({0, startGene});
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int steps = front.first;
            string word = front.second;
            if (word == endGene) return steps;
            for (int i = 0; i < word.length(); i++){
                char original = word[i];
                for (char ch = 'A'; ch <= 'Z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        q.push({steps + 1, word});
                        st.erase(word);
                    }
                } 
                word[i] = original;
            }
        }

        return -1;
    }
};