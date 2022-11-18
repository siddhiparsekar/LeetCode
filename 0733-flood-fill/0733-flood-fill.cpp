class Solution {
public:
    void flood(int i,int j,vector<vector<int>>& image,int oldcolor,int color,int n, int m ){

        if(i<0 ||j<0 ||i==n||j==m || image[i][j]!=oldcolor)return;
        
        image[i][j]=color;
        flood(i-1,j,image,oldcolor,color,n,m);
        flood(i+1,j,image,oldcolor,color,n,m);
        flood(i,j-1,image,oldcolor,color,n,m);
        flood(i,j+1,image,oldcolor,color,n,m);
        
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size(),m=image[0].size();
        
        int oldcolor=image[sr][sc];
        if(oldcolor==color)return image;
        
        flood(sr,sc,image,oldcolor,color,n,m);
        return image;
    }
};