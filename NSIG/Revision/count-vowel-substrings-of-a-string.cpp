class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int countVowelSubstrings(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[5] = {0};  // a, e, i, o, u
            int unique = 0;

            for (int j = i; j < n; j++) {
                if (!isVowel(word[j]))
                    break;   // vowel substring must be continuous

                int idx;
                if (word[j] == 'a') idx = 0;
                else if (word[j] == 'e') idx = 1;
                else if (word[j] == 'i') idx = 2;
                else if (word[j] == 'o') idx = 3;
                else idx = 4;

                if (freq[idx] == 0)
                    unique++;

                freq[idx]++;

                if (unique == 5)
                    ans++;
            }
        }

        return ans;
    }
};
