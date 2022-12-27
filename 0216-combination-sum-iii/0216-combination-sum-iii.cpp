class Solution {
public:
    void helper(int num, int k, int sum, vector<int>&ds, vector<vector<int>>&ans){
        
        if(ds.size() == k){
            if(sum == 0){
                ans.push_back(ds);
                return;
            }
        }
        if(num == 10)return;
        
        //PICK
        if(num <= sum){
            ds.push_back(num);
            helper(num+1, k, sum-num, ds, ans);;
            ds.pop_back();
        }
        
        //NOTPICK
        helper(num+1, k, sum, ds, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(1, k, n, ds, ans);
        return ans;
    }
};