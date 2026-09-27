class Solution {
     int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS=grid.size();
        int COLS=grid[0].size();
        int maxarea=0;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(grid[r][c]==1){
                    int area=0;
                    dfs(grid,r,c,area);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    
        
        
    }
    void dfs(vector<vector<int>>&grid,int r,int c,int &area){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0)
            return;
        
        grid[r][c]=0;
        area++;
        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            dfs(grid, nr, nc, area);
        }
    }
};
