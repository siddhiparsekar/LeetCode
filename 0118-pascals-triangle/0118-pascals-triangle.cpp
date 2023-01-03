class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1); 
            ans[i][0] = 1;
            for(int j=1; j<i; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            ans[i][i] = 1;
        }
        return ans;
    }
};
//resize function will help to set column equal to row size as lets take this example when we are moving in pascal at each row we can see rows equals to column so we want to set that size so at row third we need 4 rows to get equal to column.