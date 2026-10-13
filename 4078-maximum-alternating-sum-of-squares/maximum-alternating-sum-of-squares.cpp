class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Take absolute values so sorting arranges by magnitude
        for (int &x : nums) {
            x = abs(x);
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long long result = 0;
        int negCount = n / 2; // The smallest n/2 elements are subtracted
        
        for (int i = 0; i < negCount; i++) {
            result -= 1LL * nums[i] * nums[i];
        }
        for (int i = negCount; i < n; i++) {
            result += 1LL * nums[i] * nums[i];
        }
        
        return result;
    }
};