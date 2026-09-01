class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int current_sum = 0;
        int max_sum = 0;
        
        // 1. Find the sum of the first 'k' elements
        for(int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        // 2. Initialize max_sum with the sum of the first window
        max_sum = current_sum;
        
        // 3. Slide the window through the rest of the array
        for(int i = k; i < nums.size(); i++) {
            // Add the next element, remove the element that left the window
            current_sum = current_sum + nums[i] - nums[i - k];
            max_sum = max(max_sum, current_sum);
        }
        
        // 4. Return the average (cast to double to preserve decimals)
        return (double)max_sum / k;
    }
};