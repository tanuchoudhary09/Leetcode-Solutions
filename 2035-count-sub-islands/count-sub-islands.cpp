class Solution {
public:
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, -1, 0, 1};
    void dfs(int r,int c,vector<vector<int>>&vst,vector<vector<int>>&grid1,vector<vector<int>>&grid2,bool &flag){
        vst[r][c]=1;
        int n = grid2.size();
        int m = grid2[0].size();
        for(int i=0;i<4;i++){
            int nr = r+ dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vst[nr][nc] && grid2[nr][nc]==1) {
                if(grid1[nr][nc]!=1){
                    flag = false; 
                }else dfs(nr,nc,vst,grid1,grid2,flag);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(),m = grid1[0].size();
        vector<vector<int>>vst(n,vector(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                bool flag = true;
                if(grid1[i][j]==1 && !vst[i][j] && grid2[i][j]==1) {
                    dfs(i,j,vst,grid1,grid2,flag );
                    if(flag) count++;
                }
                
            }
            
        }
        return count;
    }
};