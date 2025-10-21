#include <algorithm> // For std::min

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        
        // Loop through all possible candy counts for the first child
        // We can't give more than 'n' or 'limit' candies.
        for (int c1 = 0; c1 <= std::min(n, limit); ++c1) {
            
            // Loop through all possible candy counts for the second child
            // We can't give more than 'limit' or the remaining (n - c1) candies.
            for (int c2 = 0; c2 <= std::min(limit, n - c1); ++c2) {
                
                // Calculate the remaining candies for the third child
                int c3 = n - c1 - c2;
                
                // Check if the third child's count is valid (it's already >= 0
                // because of the loop bounds, so we just check the upper limit).
                if (c3 <= limit) {
                    count++;
                }
            }
        }
        
        return count;
    }
};