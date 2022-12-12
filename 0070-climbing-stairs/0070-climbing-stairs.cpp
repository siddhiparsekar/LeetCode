class Solution {
public:
    int climb(int idx, vector<int>&dp ){
        
        if(idx<0) return 0;
        if(idx == 1 || idx == 0) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        int left = climb(idx-1, dp);
        int right = climb(idx-2, dp);
        
        return dp[idx] = (left +right);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
        return climb(n, dp);
    }
};