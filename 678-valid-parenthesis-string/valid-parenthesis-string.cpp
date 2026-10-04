#include <string>
#include <algorithm>

class Solution {
public:
    bool checkValidString(std::string s) {
        int cmin = 0; // Minimum possible open '('
        int cmax = 0; // Maximum possible open '('

        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--; // Treat '*' as ')'
                cmax++; // Treat '*' as '('
            }

            // More ')' than '(' and '*' combined
            if (cmax < 0) return false;

            // cmin cannot drop below 0 because we don't need to match
            // a '(' that hasn't appeared yet.
            cmin = std::max(cmin, 0);
        }

        return cmin == 0;
    }
};
