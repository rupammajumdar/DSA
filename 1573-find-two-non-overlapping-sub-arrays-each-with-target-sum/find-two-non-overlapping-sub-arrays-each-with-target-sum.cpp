class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        int left = 0, sum = 0, ans = INT_MAX, best_so_far = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            // Shrink the window if the sum exceeds the target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            // When a valid sub-array is found
            if (sum == target) {
                int curr_len = right - left + 1;
                
                // If there's a non-overlapping valid sub-array before the current one
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                
                // Track the minimum length found so far
                best_so_far = min(best_so_far, curr_len);
            }
            
            // Store the minimum valid sub-array length up to the current index
            min_len[right] = best_so_far;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};