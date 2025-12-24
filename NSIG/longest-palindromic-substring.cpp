class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        string ans = "";
        int maxi = 0;
        for (int i = 0; i < n; i++){
            int j = i;
            int k = i;
            string temp = "";
            while (j >= 0 && k < n){
                if (s[j] != s[k]) break;
                if (k - j + 1 > maxi) {
                    ans = s.substr(j, k - j + 1);
                    maxi = k - j + 1;
                }
                j--;
                k++;
            }
            j = i;
            k = i + 1;
            while (j >= 0 && k < n){
                if (s[j] != s[k]) break;
                if (k - j + 1 > maxi){
                    ans = s.substr(j, k - j + 1);
                    maxi = k - j + 1;
                }
                j--;
                k++;
            }
        }

        return ans;
    }
};


// find longest palindromic substring
// s = babad
// ans -> bab and aba ->bab
// palindromes -> a, aba, aabaa, ....-> odd ones
//             -> aa, aaaa, aaaaaa .... -> even ones
//           -> I've to keep track of odd ones and even ones simultanesously
// ' 

// Logic
// babad
// i, j -> I have to check the substrings of odd and even length
// b -> odd length
// ba -> a , bab, 3*m
//  i

// s = babad
//     ij   i.e j = i + 1 -> it will consider even cases

// T.C -> O(n*n)
// S.C -> O(1)