#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> tree_sum;
    vector<long long> tree_sq;
    vector<long long> lazy;

    void apply(int node, int l, int r, long long val) {
        val %= MOD;
        long long len = r - l + 1;
        // (x + val)^2 = x^2 + 2*val*x + val^2
        tree_sq[node] = (tree_sq[node] + 2 * val % MOD * tree_sum[node] % MOD + val * val % MOD * len % MOD) % MOD;
        tree_sum[node] = (tree_sum[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            update(2 * node, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(2 * node + 1, mid + 1, r, ql, qr, val);
        }
        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last_pos.count(nums[i]) ? last_pos[nums[i]] : -1;
            
            // Increment distinct count for all subarrays starting in (prev, i]
            update(1, 0, n - 1, prev + 1, i, 1);
            
            // tree_sq[1] maintains the sum of squared distinct counts for all j in [0, i]
            ans = (ans + tree_sq[1]) % MOD;
            
            last_pos[nums[i]] = i;
        }

        return ans;
    }
};