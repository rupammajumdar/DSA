class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            // The height of the container is limited by the shorter line
            int currentHeight = min(height[left], height[right]);
            int width = right - left;
            
            // Calculate area and update maxWater if it's the largest so far
            int currentArea = currentHeight * width;
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer of the shorter line inward to try and find a taller one
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};