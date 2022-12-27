class Solution {
    
public:
    vector<vector<int>> ans;
    void findsubsets(int indx, vector<int>& nums, vector<int>&ds){
        if(indx==nums.size()){
            ans.push_back(ds);
            return;
        }
        //PICK
        ds.push_back(nums[indx]);
        findsubsets(indx+1,nums,ds);
        ds.pop_back();
        //NOTPICK
        findsubsets(indx+1,nums,ds);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        findsubsets(0,nums,ds);
        return ans;
    }
};