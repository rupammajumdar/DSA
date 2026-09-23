class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum - x;
        
        // If the total sum is exactly x, we must remove all elements
        if (target == 0) return nums.size();
        
        // If the total sum is less than x, it's impossible
        if (target < 0) return -1;
        
        int max_len = -1;
        int current_sum = 0;
        int left = 0;
        
        // Sliding window
        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];
            
            // Shrink the window if the sum exceeds the target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            // If we found a valid subarray, update max_len
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // If max_len is still -1, no valid subarray was found
        return max_len == -1 ? -1 : nums.size() - max_len;
    }
};