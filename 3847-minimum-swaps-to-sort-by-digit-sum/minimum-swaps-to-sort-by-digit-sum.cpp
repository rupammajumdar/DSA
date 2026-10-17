class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store {digitSum, value, original_index}
        vector<pair<pair<int, int>, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {{digitSum(nums[i]), nums[i]}, i};
        }

        // Sort based on digitSum, then value as tie-breaker
        sort(arr.begin(), arr.end());

        // Find permutation cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // If element is already visited or in its correct spot
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            // Trace the cycle
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second; // Next index in the cycle
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};