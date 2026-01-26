class Solution {
  public:
    int countSubstring(string s) {
        int n = s.length();
        int hash[3] = {0};
        int l = 0;
        int r = 0;
        int count = 0;
        
        while (r < n){
            hash[s[r] - 'a']++;
            while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0){
                count += n - r;
                hash[s[l] - 'a']--;
                l++;
            }
            
            r++;
        }
        
        return count;
    }
};




// Brute force
// T.C -> O(n*n)
// S.C -> O(1)                    count += n -j;


// Optimal Approach
// s = abcabc
// abc-> atleast once -> then it is clear... all the substring which follows will also contain abc atleast so 
//       count += n - r;
//       [l....r] -> n - r
//       [l - 1] -> iff it contains all the three elements
//       then again check sum == 3 ? or not
      

