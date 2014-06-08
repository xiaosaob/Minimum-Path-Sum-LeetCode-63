// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<int> table(n, INT_MAX);
        table[0] = 0;
        for(int i = 0; i < m; ++i) {
            table[0] += grid[i][0];
            for(int j = 1; j < n; ++j) 
                table[j] = min(table[j],table[j-1])+grid[i][j];
        }
        return table[n-1];
    }
};
