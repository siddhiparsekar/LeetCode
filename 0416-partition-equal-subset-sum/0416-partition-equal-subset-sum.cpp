class Solution {
public:
     bool solve(int index,int target, vector<int>&arr, int N, int sum,vector<vector<int>>&dp){
        if(index>=N) return false ;
        if(sum>target) return false;
        if(sum==target) return true;
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool take=solve(index+1,target,arr,N,sum+arr[index],dp);
        bool nottake=solve(index+1,target,arr,N,sum,dp);
        return dp[index][sum]= (take || nottake);
    }
    public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int N=arr.size();
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return solve(0,target,arr,N,0,dp);
    }
};