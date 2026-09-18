class Solution {
public:
    // Helper function to find the valid rightmost bound for a substring starting at index i
    int getRightBound(const string& s, int i, const vector<int>& first, const vector<int>& last) {
        int right = last[s[i] - 'a'];
        for (int j = i; j <= right; ++j) {
            // If a character inside the current range starts before 'i', 
            // this cannot be a valid independent substring starting at 'i'.
            if (first[s[j] - 'a'] < i) {
                return -1;
            }
            // Expand the right boundary to include all occurrences of s[j]
            right = max(right, last[s[j] - 'a']);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.length();
        
        // Step 1: Find first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        // Step 2: Collect all valid intervals
        vector<pair<int, int>> intervals; // {right_bound, left_bound}
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1) {
                int right = getRightBound(s, first[i], first, last);
                if (right != -1) {
                    intervals.push_back({right, first[i]});
                }
            }
        }
        
        // Step 3: Sort intervals by their end index (Greedy approach)
        sort(intervals.begin(), intervals.end());
        
        // Step 4: Greedily pick non-overlapping substrings
        vector<string> ans;
        int prevEnd = -1;
        for (const auto& interval : intervals) {
            int right = interval.first;
            int left = interval.second;
            
            // If the current valid interval starts after the end of the last picked one
            if (left > prevEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                prevEnd = right;
            }
        }
        
        return ans;
    }
};