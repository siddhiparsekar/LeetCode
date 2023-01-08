class Solution {
public:
    int majorityElement(vector<int>& nums) {
              
        //unordered_map ->TC: O(n), SC: O(n)
        
        // int n = nums.size();
        // int ans = 0;
        // unordered_map<int, int>map;
        // for(auto value: nums){
        //     map[value]++;
        // }
        // for(auto value: map){
        //     if(value.second > n/2)
        //         ans = value.first;
        // }
        // return ans;
        
        //We use MOORE'S VOTING ALGO, in which we keep increasing and decreasing the value of count when we come across new element
        //TC: O(n), SC: O(1)
//         int candidate = 0;
//         int count = 0;
        
//         for(auto num: nums){
//             if(count == 0)
//                 candidate = num;
//             if(num == candidate)
//                 count++;
//             else
//                 count--;
//         }
        //whatever is there in the candidate is the majority element
//         return candidate; 
        
        //Sorting the given nums array
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n/2];
    }
};