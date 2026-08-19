class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Calculate the middle index (avoids integer overflow compared to (left + right) / 2)
            int mid = left + (right - left) / 2; 
            
            // If the target is found at the middle, return the index
            if (nums[mid] == target) {
                return mid;
            } 
            // If target is greater, ignore the left half
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            // If target is smaller, ignore the right half
            else {
                right = mid - 1;
            }
        }
        
        // Target was not found in the array
        return -1; 
    }
};