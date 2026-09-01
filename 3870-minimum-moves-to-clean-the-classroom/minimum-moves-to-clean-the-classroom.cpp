class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        // Map to assign a unique bit ID (0 to k-1) to each piece of litter
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int k = 0; // Total number of litter pieces
        int start_r = 0, start_c = 0;
        
        // 1. Locate the Start (S) and label all Litter (L)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = k++;
                }
            }
        }
        
        // If there's no litter, we are already done!
        if (k == 0) return 0;
        
        // This is the bitmask when ALL litter is collected
        int target_mask = (1 << k) - 1;
        
        // 3D Array to track the maximum energy we've had at a specific (row, col) with a specific collected mask
        // Initialize with -1. If we revisit a state with less or equal energy, it's a redundant path.
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        
        struct State {
            int r, c, mask, energy_left, moves;
        };
        
        queue<State> q;
        q.push({start_r, start_c, 0, energy, 0});
        bestEnergy[start_r][start_c][0] = energy;
        
        // Direction vectors for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // 2. Start Breadth-First Search
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            // Try all 4 possible moves
            for (int d = 0; d < 4; d++) {
                int next_r = curr.r + dr[d];
                int next_c = curr.c + dc[d];
                
                // Check bounds and obstacles
                if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n) continue;
                if (classroom[next_r][next_c] == 'X') continue;
                
                // Calculate new energy after taking the step
                int next_energy = curr.energy_left - 1;
                
                // If we ran out of energy (and we aren't stepping onto a reset tile right now), invalid move
                if (next_energy < 0) continue;
                
                int next_mask = curr.mask;
                
                // If it's a reset tile, energy goes back to max
                if (classroom[next_r][next_c] == 'R') {
                    next_energy = energy;
                }
                
                // If it's litter, update our collected mask
                if (classroom[next_r][next_c] == 'L') {
                    next_mask |= (1 << litter_id[next_r][next_c]);
                }
                
                // Did we just collect the last piece of litter? 
                // Since this is BFS, this is guaranteed to be the shortest path.
                if (next_mask == target_mask) {
                    return curr.moves + 1;
                }
                
                // Pruning: Have we been to this cell, with this exact same litter collected, 
                // and had MORE (or equal) energy? If so, drop this path to save time.
                if (next_energy <= bestEnergy[next_r][next_c][next_mask]) continue;
                
                // Record the new best energy for this state and queue it up
                bestEnergy[next_r][next_c][next_mask] = next_energy;
                q.push({next_r, next_c, next_mask, next_energy, curr.moves + 1});
            }
        }
        
        // If the queue empties and we haven't returned a result, it's impossible.
        return -1;
    }
};