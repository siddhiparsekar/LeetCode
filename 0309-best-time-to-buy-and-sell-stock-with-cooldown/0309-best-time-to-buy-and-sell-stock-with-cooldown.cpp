class Solution {
public:
    //MEMOIZATION
//     int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>dp){
        
//         if(idx >= prices.size()) return 0;
        
//         if(dp[idx][buy] != -1) return dp[idx][buy];
//         int profit = 0;
//         if(buy){
//             profit = max(-prices[idx] + helper(idx+1, 0, prices, dp),
//                         0 + helper(idx+1, 1, prices, dp));
//         }
//         else{
//             profit = max(prices[idx] + helper(idx+2, 1, prices, dp),
//                         0 + helper(idx+1, 0, prices, dp));
//         }
//         return dp[idx][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<int>>dp(n, vector<int>(2, -1));
//         return helper(0, 1, prices, dp);
//     }
    
    //TABULATION
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<long>>dp(n+2, vector<long>(2, 0));
        
        // dp[n][0] = dp[n][1] = dp[n+1][0] = dp[n+1][1] = 0; //Base case
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[idx] + dp[idx+1][0],
                        0 + dp[idx+1][1]);
                }
                else{
                    profit = max(prices[idx] + dp[idx+2][1],
                        0 + dp[idx+1][0]);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};