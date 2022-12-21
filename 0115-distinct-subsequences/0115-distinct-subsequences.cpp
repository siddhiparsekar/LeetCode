class Solution {
public:
    int numDistinct(string s, string t) {
        //TABULATION
//         int n = s.size();
//         int m = t.size();
        
//         vector<double>prev(m+1, 0), curr(m+1, 0);
        
//         prev[0] = curr[0] = 1; //first element must be 1 according to base case
        
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
                
//                 if(s[i-1] == t[j-1]){
//                     curr[j] = prev[j-1] + prev[j];
//                 }
//                 else{
//                     curr[j] = prev[j];
//                 }
//             }
//             prev = curr;
//         }
//         return (int)prev[m];
       
        
        //SPACE OPTIMISATION 1D-DP
        int n = s.size();
        int m = t.size();
        
        vector<double>dp(m+1, 0);
        
        dp[0] = 1; //first element must be 1 according to base case
        
        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }
        return (int)dp[m];
        
    }
};