class Solution {
public:
    void helper(int col, vector<int>&leftrow, vector<int>&lowerDiagonal, vector<int>&upperDiagonal, vector<vector<string>>&ans, vector<string>&board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
             // checking if there is a queen in the same diagonal, low diagonal and upper diagonal 
            if(leftrow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0 ){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col-row] = 1;
                helper(col+1, leftrow, lowerDiagonal, upperDiagonal, ans, board, n);
                //BACKTRACK
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col-row] = 0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        
        vector<string> board(n, string(n, '.'));
        // vector<string>board(n);
        // string s(n, ".");
        // for(int i=0; i<n; i++){
        //     board[i] = s;
        // }
        
        vector<int>leftrow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);//HASHING
        helper(0, leftrow, lowerDiagonal, upperDiagonal, ans, board, n);
        return ans;
    }
};