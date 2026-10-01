#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push expected matching closing bracket
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                // If stack is empty or doesn't match the expected bracket
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        
        // Valid only if all opened brackets were closed
        return st.empty();
    }
};