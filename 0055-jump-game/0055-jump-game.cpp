class Solution {
public:
    // bool helper(int idx, vector<int>& nums, vector<int>& dp){
    //     if(idx >= nums.size()-1)
    //         return true;
    //     if(dp[idx] != -1)
    //         return dp[idx];
    //     bool ans = false;
    //     if(nums[idx] != 0){
    //         for(int i=1; i<=nums[idx]; i++){
    //             ans = ans | helper(idx+i, nums, dp);
    //         }
    //     }
    //     return dp[idx] = ans;
    // }
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n, -1);
    //     return helper(0, nums, dp);
    // }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, false);
        dp[n-1]=true;
        for(int idx=n-2; idx>=0; idx--){
           bool ans = false;
           if(nums[idx] != 0){
                for(int j=1; j<=nums[idx]; j++){
                    if(dp[idx+j]){
                        dp[idx]=true;
                        break;
                    }
                        
                }
            }
 
        }
        return dp[0];
    }
};