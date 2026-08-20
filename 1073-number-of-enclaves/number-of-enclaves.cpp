class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vst,vector<vector<int>>&grid){
        vst[r][c]=1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dr = {-1,0,1,0};
        vector<int>dc= {0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr = r+ dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vst[nr][nc] && grid[nr][nc]==1) dfs(nr,nc,vst,grid);
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vst(n,vector<int>(m,0));
        for(int j =0;j<m;j++){
            if(!vst[0][j] && grid[0][j]==1) dfs(0,j,vst,grid);
            if(!vst[n-1][j] && grid[n-1][j]==1) dfs(n-1,j,vst,grid);
        }
        for(int j =0;j<n;j++){
            if(!vst[j][0] && grid[j][0]==1) dfs(j,0,vst,grid);
            if(!vst[j][m-1] && grid[j][m-1]==1) dfs(j,m-1,vst,grid);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vst[i][j]==0) count++;
            }
        }
        return count;
    }
};