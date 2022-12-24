class Solution {
public:
    //1] Approach 1:- MEMOISATION ->3D DP
//     int helper(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>&dp) {
        
//         if(cap == 0)return 0;
//         if(idx == prices.size()) return 0;
        
//         if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
//         int profit = 0;
//         if(buy){
//             profit = max(-prices[idx] + helper(idx+1, 0, cap, prices, dp),
//                         0 + helper(idx+1, 1, cap, prices, dp));
//         }
//         else{
//             profit = max(prices[idx] + helper(idx+1, 1, cap-1, prices, dp),
//                         0 + helper(idx+1, 0, cap, prices, dp));
//         }
//         return dp[idx][buy][cap] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return helper(0, 1, 2, prices, dp);

//     }
    
    //TABULATION ->3D 
//     int maxProfit(vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
//         //base case skipped siince dp is already declared with 0 value in it, hence starting with next values of idx & cap
//         for(int idx=n-1; idx>=0; idx--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int cap=1; cap<=2;cap++){
//                     int profit = 0;
//                     if(buy){
//                         profit = max(-prices[idx] + dp[idx+1][0][cap],
//                             0 + dp[idx+1][1][cap]);
//                     }
//                     else{
//                         profit = max(prices[idx] + dp[idx+1][1][cap-1],
//                             0 + dp[idx+1][0][cap]);
//                     }
//                     dp[idx][buy][cap] = profit;
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
    
//     //SPACE OPTIMISATION
//         int maxProfit(vector<int>& prices) {
        
//             int n = prices.size();
//             vector<vector<int>>prev(2, vector<int>(3, 0));
//             vector<vector<int>>curr(2, vector<int>(3, 0));
            
//             //base case skipped siince dp is already declared with 0 value in it, hence starting with next values of idx & cap
//             for(int idx=n-1; idx>=0; idx--){
//                 for(int buy=0; buy<=1; buy++){
//                     for(int cap=1; cap<=2;cap++){
//                         int profit = 0;
//                         if(buy){
//                             profit = max(-prices[idx] + prev[0][cap],
//                                 0 + prev[1][cap]);
//                         }
//                         else{
//                             profit = max(prices[idx] + prev[1][cap-1],
//                                 0 + prev[0][cap]);
//                         }
//                         curr[buy][cap] = profit;
//                     }
//                 }
//                 prev=curr;
            
//             }
//             return prev[1][2];
//     }
    
    //2] Approach 2:- MEMOISATION ->2D DP
//         int helper(int idx, int ts, int n, vector<int>&prices, vector<vector<int>>&dp){
        
//             //base cases
//             if(idx == n || ts == 4) return 0;
            
//             if(dp[idx][ts] != -1) return dp[idx][ts];
//             if(ts%2 == 0){
//                 return dp[idx][ts] = max(-prices[idx] + helper(idx+1, ts+1, n, prices, dp),
//                                          0 + helper(idx+1, ts, n, prices, dp));
//             }
//             else{
//                 return dp[idx][ts] = max(prices[idx] + helper(idx+1, ts+1, n, prices, dp),
//                                          0 + helper(idx+1, ts, n, prices, dp));
//             }
//         }
    
//         int maxProfit(vector<int>& prices){
            
//             int n = prices.size();
//             vector<vector<int>>dp(n, vector<int>(4, -1));
//             return helper(0, 0, n, prices, dp);           // in this approach we set buy=0 unlike approach 1, for it to be bought as we check for ts%2==0
//         }
    
    //TABULATION ->2D
//         int maxProfit(vector<int>& prices){
//             int n = prices.size();
//             vector<vector<int>>dp(n+1, vector<int>(5,-0));
        
//             //base case skipped siince dp is already declared with 0 value in it, hence starting with next values of idx & ts
//             for(int ind=n-1; ind>=0; ind--){
//                 for(int ts=3; ts>=0; ts--){
//                     if(ts%2 == 0){
//                         dp[ind][ts] = max(-prices[ind] + dp[ind+1][ts+1],
//                                           0 + dp[ind+1][ts]);
//                     }
//                     else{
//                         dp[ind][ts] = max(prices[ind] + dp[ind+1][ts+1],
//                                           0 + dp[ind+1][ts]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
    
        int maxProfit(vector<int>& prices){
            int n = prices.size();
            vector<int>prev(5,-1),cur(5,-1);
            for(int i=0;i<=4;i++){
                prev[i] = 0;
            }
            cur[4]=0;
            for(int ind=n-1;ind>=0;ind--){
                for(int ts = 3;ts>=0;ts--){
                    if(ts%2==0){
                        cur[ts] = max(-prices[ind]+prev[ts+1],prev[ts]);
                    }
                    else {
                        cur[ts] = max(prices[ind]+prev[ts+1],prev[ts]);
                    }
                }
                prev = cur;
            }
            return prev[0];
        }
};