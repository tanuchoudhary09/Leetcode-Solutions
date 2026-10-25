class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>& grid, vector<int>& dr, vector<int>& dc, vector<vector<int>>& vst, int& cnt, int n, int m){
        if(r<0 || c<0 || r>=n || c>=m) return false; 
        if(grid[r][c]==1 || vst[r][c]) return true;
        vst[r][c] = 1;
        bool flag = true;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!dfs(nr,nc,grid,dr,dc,vst,cnt,n,m)) flag = false;
        }
        return flag;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vst(n,vector<int>(m,0));
        vector<int>dr = {1,0,-1,0};
        vector<int>dc = {0,1,0,-1};
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vst[i][j]) {
                    if(dfs(i,j,grid,dr,dc,vst,cnt,n,m)) cnt++;
                }
            }
        }
        return cnt;
    }
};