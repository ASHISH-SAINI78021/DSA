//User function template for C++

class Solution {
public:
    long long int substrCount(string s, int k) {
        return countSubstringsWithAtMostKDistinct(s, k) - countSubstringsWithAtMostKDistinct(s, k - 1);
    }

private:
    long long int countSubstringsWithAtMostKDistinct(const string& s, int k) {
        if (k == 0) return 0;

        unordered_map<char, int> charCount;
        int left = 0;
        long long int result = 0;

        for (int right = 0; right < s.length(); ++right) {
            charCount[s[right]]++;

            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }
};

