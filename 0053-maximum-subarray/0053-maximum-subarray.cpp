class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxsum = INT_MIN;
        for(int i=0; i<n; i++){
            //find the summation at each index
            sum += nums[i];
            //find the max sum.
            maxsum = max(maxsum, sum);
            //if the sumation is less than 0, than update the sum to 0 since we dont want to carry the negative sum
            if(sum<0) 
                sum = 0;
        }
        return maxsum;
    }
};