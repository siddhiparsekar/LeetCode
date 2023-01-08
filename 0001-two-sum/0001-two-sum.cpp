class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Naive Approach -> TC: O(n^2), SC: O(1)
//         int sum=0;
//         vector<int>v;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
                
//                 sum=nums[i]+nums[j];
//                 if(sum==target){
//                     v.push_back(i);
//                     v.push_back(j);
//                     break;
//                 }
                
//             }
//         }
//         return v;
        
        //unordered map -> TC: O(n), SC: O(N)
        int n = nums.size();
        vector<int>ans;
        unordered_map<int, int>map;
        
        for(int i=0; i<n; i++){
            int x = target-nums[i];
            if(map.find(x) != map.end()){
                ans.push_back(map[x]);
                ans.push_back(i);
                break;
            } 
            else{
                 map[nums[i]] = i;
            }
        }
        return ans;
    }
};