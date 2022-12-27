class Solution {
public:
    
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
