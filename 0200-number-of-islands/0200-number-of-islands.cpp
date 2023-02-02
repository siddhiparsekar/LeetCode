class Solution {
public:
//     void bfs(int row, int col, vector<vector<char>>& grid,  vector<vector<int>>&vis){
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<pair<int, int>>q;
//         q.push({row, col});
        
//         vis[row][col]=1;
//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();
            
//             //Traverse in the neighbors and mark them in the vis array
//             for(int delrow=-1; delrow<=1; delrow++){
//                 for(int delcol=-1; delcol<=1; delcol++){
//                     int nrow = row + delrow;
//                     int ncol = col + delcol;
                    
//                     if(nrow>=0 && nrow<m && nrow>=0 && nrow<m && !vis[nrow][ncol] && grid[nrow][ncol] == "1"){
//                         vis[nrow][ncol] =1;
//                         q.push({nrow, ncol});
//                     }
//                 }
//             }
            
//         } 
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<vector<int>>vis(n, vector<int>(m, 0));
//         int count = 0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(!vis[i][j] && grid[i][j] == "1"){
//                     count++;
//                     bfs(i, j, grid, vis);
//                 }
//             }
//         }
//         return count;
//     }
    
        void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>> grid) {
        vis[row][col] = 1;
        queue<pair<int, int> > q;
        q.push({row, col});
        
        while(!q.empty()) {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            //for neighbouring lands.
            for(int drow=-1; drow<=1; drow++) {
                for(int dcol=-1; dcol<=1; dcol++){
                    if(drow==-1&&dcol==0||drow==0&&dcol==1||drow==1&&dcol==0||drow==0&&dcol==-1){
                        int nrow=row+drow;
                        int ncol=col+dcol;
                        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() 
                           && grid[nrow][ncol]=='1' && !vis[nrow][ncol]) {
                            vis[nrow][ncol]=1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > vis(n, vector<int>(m,0));
        int count=0;
        
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};