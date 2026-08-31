class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // If the list has fewer than 3 nodes, there can be no critical points.
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int first_crit_idx = -1;
        int prev_crit_idx = -1;
        int min_dist = INT_MAX;
        
        int curr_idx = 1; // 'head' is at index 0, 'curr' starts at index 1

        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;
            
            // Check if the current node is a critical point (local maxima or minima)
            if ((curr->val > prev->val && curr->val > next_node->val) ||
                (curr->val < prev->val && curr->val < next_node->val)) {
                
                if (first_crit_idx == -1) {
                    // This is the very first critical point we've found
                    first_crit_idx = curr_idx;
                } else {
                    // This is at least the second critical point, calculate distance
                    int dist = curr_idx - prev_crit_idx;
                    min_dist = min(min_dist, dist);
                }
                
                // Update the previous critical point index to the current one
                prev_crit_idx = curr_idx;
            }
            
            // Move our window of three nodes forward
            prev = curr;
            curr = next_node;
            curr_idx++;
        }

        // If min_dist is still INT_MAX, we found fewer than 2 critical points
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }

        // The maximum distance is always the distance between the first and last critical points found
        int max_dist = prev_crit_idx - first_crit_idx;
        
        return {min_dist, max_dist};
    }
};