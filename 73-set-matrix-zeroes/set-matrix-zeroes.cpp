#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     // Function to set entire row and column to 0 if an element in the matrix is 0
    void setZeroes(vector<vector<int>>& matrix) {
        // Get number of rows
        int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);

        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is zero
                if (matrix[i][j] == 0) {
                    row[i]=1;
                    col[j]=1;
            }
        }
        }

        // Second pass: replace all -1 markers with 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i]==1|| col[j]==1)
                    matrix[i][j] = 0;
            }
        }
    }
    
};


