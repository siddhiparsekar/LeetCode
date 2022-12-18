class Solution {
public:
    int helper(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
        
        if(idx == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int nottake = 0 + helper(idx-1, coins, amount, dp);
        int take = INT_MAX;
        if(coins[idx] <= amount)
            take = 1 + helper(idx, coins, amount-coins[idx], dp);
            
        return dp[idx][amount] = min(take, nottake);            
            
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = helper(n-1, coins, amount, dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};