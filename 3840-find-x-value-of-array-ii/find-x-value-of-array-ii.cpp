class Solution {
    struct Node {
        int total_prod;
        int freq[5]; // k is guaranteed to be <= 5
        
        Node() {
            total_prod = 1;
            for (int i = 0; i < 5; ++i) {
                freq[i] = 0;
            }
        }
    };

    Node merge(const Node& left, const Node& right, int k) {
        Node res;
        // Total product of the merged segment
        res.total_prod = (left.total_prod * right.total_prod) % k;
        
        // 1. Prefixes that end in the left child
        for (int i = 0; i < k; ++i) {
            res.freq[i] = left.freq[i];
        }
        
        // 2. Prefixes that span across into the right child
        for (int i = 0; i < k; ++i) {
            if (right.freq[i] > 0) {
                res.freq[(left.total_prod * i) % k] += right.freq[i];
            }
        }
        
        return res;
    }

    vector<Node> tree;

    void build(int node, int start, int end, const vector<int>& nums, int k) {
        if (start == end) {
            int val = nums[start] % k;
            tree[node].total_prod = val;
            tree[node].freq[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums, k);
        build(2 * node + 1, mid + 1, end, nums, k);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], k);
    }

    void update(int node, int start, int end, int idx, int val, int k) {
        if (start == end) {
            tree[node] = Node(); // Reset frequencies
            int mod_val = val % k;
            tree[node].total_prod = mod_val;
            tree[node].freq[mod_val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val, k);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val, k);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], k);
    }

    Node query(int node, int start, int end, int l, int r, int k) {
        if (r < start || end < l) {
            return Node(); // Identity node (total_prod = 1, all freq = 0)
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        Node left_res = query(2 * node, start, mid, l, r, k);
        Node right_res = query(2 * node + 1, mid + 1, end, l, r, k);
        return merge(left_res, right_res, k);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums, k);
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            
            // 1. Point Update
            update(1, 0, n - 1, index, value, k);
            
            // 2. Range Query from start to end of the array
            Node res = query(1, 0, n - 1, start, n - 1, k);
            
            // 3. Store requested frequency
            result.push_back(res.freq[x]);
        }
        
        return result;
    }
};