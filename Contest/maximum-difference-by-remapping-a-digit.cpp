#include <string>
#include <algorithm>

class Solution {
public:
    int minMaxDifference(int num) {
        // Use std::to_string for a clean and error-free conversion.
        std::string s_num = std::to_string(num);

        // --- Calculate Maximum Number ---
        std::string s_num_max = s_num;
        char max_target = '\0'; // Character to replace
        
        // FIX 3: Find the first digit that is NOT '9'.
        for (char c : s_num_max) {
            if (c != '9') {
                max_target = c;
                break;
            }
        }
        
        // If a target was found (i.e., the number wasn't all 9s)
        if (max_target != '\0') {
            for (char &c : s_num_max) {
                if (c == max_target) {
                    c = '9';
                }
            }
        }

        // --- Calculate Minimum Number ---
        std::string s_num_min = s_num;
        // The logic for minimum is simple: always replace the first digit with '0'.
        char min_target = s_num_min[0];
        for (char &c : s_num_min) {
            if (c == min_target) {
                c = '0';
            }
        }
        
        // Convert strings back to integers for the final calculation.
        // std::stoi handles the character-to-integer conversion correctly.
        int max_val = std::stoi(s_num_max);
        int min_val = std::stoi(s_num_min);
        
        return max_val - min_val;
    }
};