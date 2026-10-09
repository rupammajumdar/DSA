class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int insertions = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // Opening bracket ko stack me daal do
                st.push('(');
            } else {
                // Closing bracket milne par check karo ki agla character bhi ')' hai ya nahi
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Do ')' mil gaye ("))" pair ban gaya)
                } else {
                    // Agar single ')' hai, to ek ')' insert karna padega
                    insertions++;
                }

                // Ab hamare paas ek complete "))" pair hai
                // Dekho stack me koi '(' match karne ke liye hai ya nahi
                if (!st.empty()) {
                    st.pop(); // '(' ko pop karke pair complete kiya
                } else {
                    // Koi '(' nahi tha, isliye ek '(' insert karna padega
                    insertions++;
                }
            }
        }

        // Loop ke baad jitne '(' stack me bach gaye,
        // un sabhi ke liye 2 closing brackets "))" add karne padenge
        while (!st.empty()) {
            insertions += 2;
            st.pop();
        }

        return insertions;
    }
};