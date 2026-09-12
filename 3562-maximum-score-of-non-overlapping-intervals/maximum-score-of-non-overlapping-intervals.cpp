#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        struct Interval {
            int l, r, w, id;
        };
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort by right boundary
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });
        
        vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = arr[i].r;
        }
        
        // dp[c][i] stores {weight, {indices}}
        vector<vector<pair<long long, vector<int>>>> dp(
            5, vector<pair<long long, vector<int>>>(n + 1, {-1, {}})
        );
        
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = {0, {}};
        }
        
        // Helper lambda to compare states
        auto is_better = [](const pair<long long, vector<int>>& s1, const pair<long long, vector<int>>& s2) {
            if (s1.first != s2.first) {
                return s1.first > s2.first;
            }
            return s1.second < s2.second;
        };
        
        for (int i = 1; i <= n; ++i) {
            int l = arr[i-1].l;
            int r = arr[i-1].r;
            int w = arr[i-1].w;
            int id = arr[i-1].id;
            
            // Find rightmost interval ending strictly before current interval's start
            auto it = lower_bound(ends.begin(), ends.end(), l);
            int idx = distance(ends.begin(), it) - 1;
            int prev = (idx >= 0) ? idx + 1 : 0;
            
            for (int c = 1; c <= 4; ++c) {
                auto best = dp[c][i-1];
                
                if (dp[c-1][prev].first != -1) {
                    long long new_w = dp[c-1][prev].first + w;
                    vector<int> new_idx = dp[c-1][prev].second;
                    new_idx.push_back(id);
                    sort(new_idx.begin(), new_idx.end());
                    
                    pair<long long, vector<int>> cand = {new_w, new_idx};
                    if (is_better(cand, best)) {
                        best = cand;
                    }
                }
                dp[c][i] = best;
            }
        }
        
        // Compare outcomes from 1 to 4 picks
        pair<long long, vector<int>> ans = {-1, {}};
        for (int c = 1; c <= 4; ++c) {
            if (is_better(dp[c][n], ans)) {
                ans = dp[c][n];
            }
        }
        
        return ans.second;
    }
};