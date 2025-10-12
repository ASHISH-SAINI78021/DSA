#include <string>
#include <algorithm> // For std::reverse

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        
        // Pointers for the end of each string
        int i = a.length() - 1;
        int j = b.length() - 1;

        // Loop until we have processed both strings and the carry is gone
        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // The new digit is the sum modulo 2
            result += to_string(sum % 2);
            // The new carry is the sum divided by 2
            carry = sum / 2;
        }
        
        // The result string was built backwards, so reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};