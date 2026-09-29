#include <vector>

using namespace std;

class Solution {
    bool visited[101][101][105];

    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid, int m, int n) {
        // Update balance
        bal += (grid[r][c] == '(' ? 1 : -1);

        // Balance cannot drop below zero
        if (bal < 0) return false;

        // Pruning: if remaining steps cannot balance out the open brackets
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (bal > remaining_steps) return false;

        // Reached destination
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        // Check if already visited
        if (visited[r][c][bal]) return false;
        visited[r][c][bal] = true;

        // Move right
        if (c + 1 < n && dfs(r, c + 1, bal, grid, m, n)) {
            return true;
        }

        // Move down
        if (r + 1 < m && dfs(r + 1, c, bal, grid, m, n)) {
            return true;
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 != 0) return false;

        // Start must be '(' and end must be ')'
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;

        // Reset visited table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2; ++k) {
                    visited[i][j][k] = false;
                }
            }
        }

        return dfs(0, 0, 0, grid, m, n);
    }
};
