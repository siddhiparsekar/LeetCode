class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //There are only 2 types of element in the nums array       
        //unordered_map ->TC: O(n), SC: O(n)
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int>map;
        for(auto value: nums){
            map[value]++;
        }
        for(auto value: map){
            if(value.second > n/2)
                ans = value.first;
        }
        return ans;
    }
};