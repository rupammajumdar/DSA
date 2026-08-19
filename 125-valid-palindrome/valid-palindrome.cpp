class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[right])) {
                right--;
            }
            // Compare the characters after converting to lowercase
            else if (tolower(s[left]) != tolower(s[right])) {
                return false; // Not a palindrome
            }
            // Move both pointers inward if they match
            else {
                left++;
                right--;
            }
        }
        
        return true; // It is a palindrome
    }
};