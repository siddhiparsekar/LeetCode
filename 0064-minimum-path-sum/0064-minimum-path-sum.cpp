class Solution {
public:
    
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){

        if(i == 0 && j == 0)return grid[0][0];
        if(i<0 || j<0)return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + memo(i-1, j, grid, dp);
        int left = grid[i][j] + memo(i, j-1, grid, dp);
        
        return dp[i][j] = min(up , left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memo(m-1, n-1, grid, dp);
    }
};