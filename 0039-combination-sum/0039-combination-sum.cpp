class Solution {
public:
    void helper(int idx, vector<int>& arr,int target, vector<int>&ds, vector<vector<int>>&ans){
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        //PICK   
        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            helper(idx, arr,target-arr[idx], ds, ans);
            ds.pop_back();
        }
        //NOT PICK
        helper(idx+1, arr, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0, candidates, target, ds, ans);
        return ans;
    }
};