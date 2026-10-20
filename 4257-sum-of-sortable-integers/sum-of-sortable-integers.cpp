#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> s = nums;
        std::sort(s.begin(), s.end());

        // Find all divisors of n
        std::vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int total_sum = 0;

        for (int k : divisors) {
            bool possible = true;

            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int drop_idx = -1;

                // Count circular drops
                for (int j = 0; j < k; ++j) {
                    int next_j = (j + 1 == k) ? 0 : j + 1;
                    if (nums[i + j] > nums[i + next_j]) {
                        drops++;
                        drop_idx = j;
                        if (drops > 1) {
                            possible = false;
                            break;
                        }
                    }
                }

                if (!possible) break;

                // Identify the starting index of the sorted block
                int start = (drops == 0) ? 0 : (drop_idx + 1) % k;

                // Compare with the sorted segment s[i .. i + k - 1]
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (start + j) % k] != s[i + j]) {
                        possible = false;
                        break;
                    }
                }

                if (!possible) break;
            }

            if (possible) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};