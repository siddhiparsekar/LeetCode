class Solution {
public:
    
    int helper(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>&dp){
        
        if(idx == nums.size())return 0;
        
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        
        int notpick = 0 + helper(idx+1, prev_idx, nums, dp);
        
        int pick = 0;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            pick = 1 + helper(idx+1, idx, nums, dp);
        
        return dp[idx][prev_idx+1] = max(pick, notpick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return helper(0, -1, nums, dp);
    }
};