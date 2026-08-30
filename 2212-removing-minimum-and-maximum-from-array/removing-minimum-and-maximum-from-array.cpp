class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        // Agar array mein sirf 1 ya 2 elements hain, toh saare hi hatane padenge
        if (n <= 2) return n;

        int max_index = 0;
        int min_index = 0;
        
        // Ek hi loop mein max aur min ka index nikal lo
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[max_index]) {
                max_index = i;
            }
            if (nums[i] < nums[min_index]) {
                min_index = i;
            }
        }
        
        // Pata karo kaunsa index aage (left) hai aur kaunsa peeche (right)
        int left_index = min(max_index, min_index);
        int right_index = max(max_index, min_index);
        
        // Teeno possible cases:
        // Case 1: Dono ko aage se hatao
        int delete_front = right_index + 1;
        
        // Case 2: Dono ko peeche se hatao
        int delete_back = n - left_index;
        
        // Case 3: Jo aage hai usko aage se, aur jo peeche hai usko peeche se hatao
        int delete_both_sides = (left_index + 1) + (n - right_index);
        
        // Teeno cases mein se jo sabse kam steps le raha ho, wo return kardo
        return min({delete_front, delete_back, delete_both_sides});
    }
};