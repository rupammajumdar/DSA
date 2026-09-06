class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // We use unsigned int to prevent overflow issues on intermediate 
        // additions, as LeetCode only guarantees the FINAL answer fits in a 32-bit int.
        vector<unsigned int> dp(n + 1, 0);
        
        // Base case: an empty string t can be formed 1 way
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            // Iterate backwards to use the previous row's values
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};