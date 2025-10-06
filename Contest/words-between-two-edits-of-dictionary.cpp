#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> twoEditWords(std::vector<std::string>& queries, std::vector<std::string>& dictionary) {
        std::vector<std::string> ans;
        int n = queries.size();
        int m = dictionary.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diffCount = 0;
                if (queries[i].length() != dictionary[j].length()) continue;
                for (int k = 0; k < queries[i].length(); k++) {
                    if (queries[i][k] != dictionary[j][k]) {
                        diffCount++;
                    }
                }

                if (diffCount <= 2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};