#include <string>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the sum exceeds the maximum possible value with 'num' digits (all 9s)
        if (sum > 9 * num) {
            return "";
        }

        int nines = sum / 9;
        int rem = sum % 9;

        // Build the string greedily: 9s first, then remainder, then trailing 0s
        string ans = string(nines, '9');

        if (rem > 0) {
            ans += to_string(rem);
        }

        if (ans.size() < num) {
            ans.append(num - ans.size(), '0');
        }

        return ans;
    }
};