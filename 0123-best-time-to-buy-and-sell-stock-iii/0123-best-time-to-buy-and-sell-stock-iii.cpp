class Solution {
public:
    //MEMOISATION
    int helper(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>&dp) {
        
        if(cap == 0)return 0;
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + helper(idx+1, 0, cap, prices, dp),
                        0 + helper(idx+1, 1, cap, prices, dp));
        }
        else{
            profit = max(prices[idx] + helper(idx+1, 1, cap-1, prices, dp),
                        0 + helper(idx+1, 0, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, 2, prices, dp);

    }
};