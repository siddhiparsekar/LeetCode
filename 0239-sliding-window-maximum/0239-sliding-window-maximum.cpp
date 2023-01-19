class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        list<int> l;
        int i=0,j=0;
        
        while(j<nums.size()){
            
            if(l.empty()) l.push_back(nums[j]);
            else{
                while(!l.empty() && l.back()<nums[j])
                    l.pop_back();
                l.push_back(nums[j]);
            }
            
            if((j-i+1)<k) j++;
            
            else{
                
                ans.push_back(l.front());
                if(nums[i]==l.front())
                    l.pop_front();
                i++,j++;
            }
        }
        return ans;
    }
};