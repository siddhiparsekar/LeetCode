class Solution {
public:
// using SET, which takes extra O(logn) to convert it back to a vector.
    // set<vector<int>> ans;
    // void findsubsets(int indx, vector<int>& nums, vector<int>ds){
    //     if(indx==nums.size()){
    //         ans.insert(ds);
    //         return;
    //     }
    //     findsubsets(indx+1,nums,ds);
    //     ds.push_back(nums[indx]);
    //     findsubsets(indx+1,nums,ds);
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     vector<int>ds;
    //     sort(nums.begin(), nums.end());
    //     findsubsets(0,nums,ds);
    //     vector<vector<int>> ans1(ans.begin(), ans.end());
    //     return ans1;
    // }
    
//OPTIMISED ,use while loop to ignore all the following same elements
   void findcomb(int indx, vector<int>&arr, vector<vector<int>> &ans, vector<int>&ds){
        if(indx==arr.size()){
           ans.push_back(ds);
           return;
        }
        //PICK     
        ds.push_back(arr[indx]);
        findcomb(indx+1, arr, ans, ds);
        ds.pop_back();
        //NOT PICK
        while(indx+1 < arr.size() && arr[indx] == arr[indx+1])
            indx++;
        findcomb(indx+1, arr, ans, ds);
 }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ds;
        vector<vector<int>> ans;
        findcomb(0, nums, ans, ds);
        return ans;   
    }
    
};
