class Solution {
public:
    //TC: O(nlogn) + O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeintervals;
        sort(intervals.begin(), intervals.end()); //sort the array first
        vector<int>tempinterval = intervals[0]; //store the first element in the temp vector and use this to compare it the begining
        
        for(auto it : intervals){
            if(it[0] <= tempinterval[1]){
                tempinterval[1] = max(tempinterval[1], it[1]);
            }else{
                mergeintervals.push_back(tempinterval);
                tempinterval = it;
            }
        }
        mergeintervals.push_back(tempinterval);
        return mergeintervals;
    }
};