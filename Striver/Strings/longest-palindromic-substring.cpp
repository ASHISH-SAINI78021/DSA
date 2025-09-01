class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int maxi = 0;
        int start = 0;

        while (i < n){
            int low = i;
            int high = i;
            while (low >= 0 && high < n && s[low] == s[high]){
                if (high - low + 1 > maxi){
                    maxi = high - low + 1;
                    start = low;
                }
                low--;
                high++;
            }

            low = i;
            high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]){
                if (high - low + 1 > maxi){
                    maxi = high - low + 1;
                    start = low;
                }
                low--;
                high++;
            }

            i++;
        }

        return s.substr(start , maxi);
    }
};