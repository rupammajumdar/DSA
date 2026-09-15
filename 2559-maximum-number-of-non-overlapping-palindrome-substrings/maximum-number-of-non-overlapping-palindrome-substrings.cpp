class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int i = 0;
        
        // Helper lambda to check if a substring is a palindrome
        auto isPalindrome = [&](int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        };

        // Greedily find palindromes of length k or k + 1
        while (i <= n - k) {
            // Check for length k
            if (isPalindrome(i, i + k - 1)) {
                ans++;
                i += k; // Jump past this palindrome
            } 
            // Check for length k + 1
            else if (i + k < n && isPalindrome(i, i + k)) {
                ans++;
                i += k + 1; // Jump past this palindrome
            } 
            // No valid palindrome starting at i, move 1 step forward
            else {
                i++;
            }
        }
        
        return ans;
    }
};