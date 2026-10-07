#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                // If a valid string was already found at this level, 
                // do not generate deeper states (subsequent levels).
                if (found) continue;

                for (int j = 0; j < curr.length(); ++j) {
                    // Only remove parentheses
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    // Avoid duplicate branch when adjacent characters are identical
                    if (j > 0 && curr[j] == curr[j - 1]) continue;

                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    if (!visited.count(nextStr)) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }

            if (found) break;
        }

        return result;
    }
};