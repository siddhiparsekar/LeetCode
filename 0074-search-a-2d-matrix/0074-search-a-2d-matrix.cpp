class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

//PS. In LC problem elements are sorted row wise as well as column wise 
//In GFG problem variant elements are sorted row wise only and not column wise
        
    //Brute force ->linearly traverse O(m*n)
        int m = matrix.size(), n= matrix[0].size();
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(matrix[i][j]==target)
        //             return true;
        //     }
        // }
        // return false;
        
    //Better Approach(optimal for gfg variant of this problem) -> linear traversal, only one traversal needed O(n)
        // int i = 0, j = n-1;
        // while(i<m && j>=0){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }
        //     else if(matrix[i][j] > target)
        //         j--;
        //     else
        //         i++;
        // }
        // return false;
        
    //Optimal Approach -> Binary search O(log(m*n)) (not for gfg variant)
        int low = 0;
        int high = (m*n) - 1;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            if(matrix[mid/n][mid%n] == target)
                return true;
            else if(matrix[mid/n][mid%n] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};