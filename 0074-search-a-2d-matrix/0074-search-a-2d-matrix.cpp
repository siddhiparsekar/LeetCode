class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Brute force ->linearly traverse O(m*n)
        int m = matrix.size(), n= matrix[0].size();
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(matrix[i][j]==target)
        //             return true;
        //     }
        // }
        // return false;
        
        //Better Approach(works for gfg variation of this problem as well)
        int i = 0, j = n-1;
        while(i<m && j>=0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};