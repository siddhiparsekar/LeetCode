class Solution {
public:
    
    void findpermutation(int indx, vector<int>&nums,vector<vector<int>>&ans){
        if(indx==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> m;
        for(int i=indx;i<nums.size();i++){
            if(m.find(nums[i])!=m.end())continue;
            m.insert(nums[i]);
            swap(nums[i],nums[indx]);
            findpermutation(indx+1, nums,ans);
            swap(nums[i],nums[indx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        findpermutation(0, nums,ans);
        return ans;
    }
};
 