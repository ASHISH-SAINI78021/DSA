class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++){
            int freq[26] = {0};
            for (int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                int maxi = 0;
                int mini = INT_MAX;
                for (int k = 0; k < 26; k++){
                    if (freq[k] > 0){
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                sum += maxi - mini;
            }
        }

        return sum;
    }
};


// s = aabcb
// aabcb -> 2 - 1 = 1
// a -> 1 - 1 = 0
// aa -> 2 - 2 = 0
// aab -> 2 - 1 = 1
// aabc -> 2 - 1 = 1
// abcb -> 2 - 1 = 1
// a -> 1 - 1 = 0
// bcb -> 2 - 1 = 1
// cb -> 1 - 1 = 0
// b -> 1 - 1 = 0
// ........ sum = 5

// my Algo would take
// T.C -> O(n*n)
// S.C -> O(1)