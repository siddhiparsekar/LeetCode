class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        
        if(j<0 || j>=matrix.size()) return 1e9;
        if(i == 0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = 1e9;
        for(int k=0; k< matrix.size(); k++){
            
            if(k != j)mn = min(mn, matrix[i][j] + helper(i-1, k,matrix, dp));
        }
        return dp[i][j] = mn;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();  //It's a n x n matrix.
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, helper(n-1, j, matrix, dp));
        }
        return mini;
    }
};