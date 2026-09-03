class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minElement = nums1[0];
        bool allEven = true;
        
        // Find the smallest number and check if there are any odd numbers
        for (int num : nums1) {
            if (num < minElement) {
                minElement = num;
            }
            if (num % 2 != 0) {
                allEven = false; // We found an odd number
            }
        }
        
        // Condition 1: If the array is already entirely EVEN, we win.
        if (allEven) {
            return true;
        }
        
        // Condition 2: If it's a mix, the ONLY way to make them all the same 
        // (which would be making them all ODD) is if the absolute smallest number is ODD.
        if (minElement % 2 != 0) {
            return true;
        }
        
        // If it's a mix and the smallest number is even, it's impossible.
        return false;
    }
};