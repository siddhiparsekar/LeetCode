class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int cost = 0;
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            cost = prices[i] - mini;
            if(cost >= 0){
                profit = max(profit, cost);
            }
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};