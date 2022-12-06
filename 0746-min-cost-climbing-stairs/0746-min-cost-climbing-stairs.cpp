class Solution {
public:
    int f(int i,vector<int>& cost,vector<int>&dp){

        if(i<=1)return cost[i];
        
        if(dp[i]!=0)return dp[i];
        
        int left=f(i-1,cost,dp)+cost[i];
        int right=f(i-2,cost,dp)+cost[i];

        return dp[i]=min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,0);
        return min(f(n-1, cost,dp),f(n-2,cost,dp));
    }
};