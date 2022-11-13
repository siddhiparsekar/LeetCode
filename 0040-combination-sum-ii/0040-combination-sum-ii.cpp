class Solution {
void findcomb(int indx,int target,vector<int>&arr,set<vector<int>> &ans, vector<int>&ds){
        if(indx==arr.size()){
           if(target==0){
                ans.insert(ds);
            } 
            return;
        }
        
        //PICK     
        if(arr[indx]<=target){
            ds.push_back(arr[indx]);
            findcomb(indx+1,target-arr[indx],arr,ans,ds);
            ds.pop_back();
        }
        //NOT PICK
        while(indx+1< arr.size() && arr[indx]==arr[indx+1])indx++;
        findcomb(indx+1,target,arr,ans,ds);
        
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int>ds;
        findcomb(0,target,candidates,ans,ds);
        vector<vector<int>> ans1(ans.begin(), ans.end());
        return ans1;   
    }
};