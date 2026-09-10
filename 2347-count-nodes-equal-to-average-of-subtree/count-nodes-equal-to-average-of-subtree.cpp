class Solution {
    int matchingNodesCount = 0;

    // Helper function that returns a pair: {sum_of_subtree, count_of_nodes}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        
        // Traverse left and right subtrees
        pair<int, int> leftSubtree = dfs(root->left);
        pair<int, int> rightSubtree = dfs(root->right);
        
        // Calculate sum and count for the current subtree
        int currentSum = leftSubtree.first + rightSubtree.first + root->val;
        int currentCount = leftSubtree.second + rightSubtree.second + 1;
        
        // Check if the current node's value equals the average
        if (root->val == currentSum / currentCount) {
            matchingNodesCount++;
        }
        
        // Return the accumulated sum and count for the parent node to use
        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodesCount;
    }
};