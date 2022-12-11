class Solution {
public:
//     MOMOIZATION --still gives TLE
//     int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        
//         //BASE CASE
//         if(j<0 || j >= matrix[0].size())return 1e9;
//         if(i == 0)return matrix[0][j];
        
//         if(dp[i][j] != -1)return dp[i][j];
//         int straightUp = matrix[i][j] + helper(i-1, j, matrix, dp);
//         int leftDiagonal = matrix[i][j] + helper(i-1, j-1, matrix, dp);
//         int rightDiagonal = matrix[i][j] + helper(i-1, j+1, matrix, dp);
        
//         return min(straightUp, min(leftDiagonal, rightDiagonal));
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
        
//         int mini = 1e9;
//         for(int j=0; j<m; j++){
            
//             mini = min(mini, helper(n-1, j, matrix, dp));
//         }
//         return mini;
//     }
    
//   TABULATION
     int minFallingPathSum(vector<vector<int>>& matrix) {
         
         int n = matrix.size();
         int m = matrix[0].size();
         vector<vector<int>>dp(n, vector<int>(m, 0));
         
         for(int j = 0; j < m; j++){
             dp[0][j] = matrix[0][j];
         }
         for(int i=1; i<n; i++){
            for(int j=0;j<m;j++){
                
                int straightUp = matrix[i][j] + dp[i-1][j];
                
                int leftDiagonal = matrix[i][j];
                if(j-1 >= 0)leftDiagonal += dp[i-1][j-1];
                else leftDiagonal += 1e9;
                
                int rightDiagonal = matrix[i][j];
                if(j+1 < m)rightDiagonal += dp[i-1][j+1];
                else rightDiagonal += 1e9;
                
                dp[i][j] = min(straightUp, min(leftDiagonal, rightDiagonal));
                
            }
         }
         int mini = 1e9;
         for(int j=0; j<m; j++){
              mini = min(mini, dp[n-1][j]);
         }
         return mini;
     }
};