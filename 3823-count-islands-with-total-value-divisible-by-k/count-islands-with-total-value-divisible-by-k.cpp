class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, vector<int>& dr, vector<int>& dc, int m, int n, long long& cnt){
        cnt += grid[r][c];
        grid[r][c] = 0;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!(nr<0 || nc<0 || nc>=n || nr>=m) && grid[nr][nc]) dfs(grid,nr,nc,dr,dc,m,n,cnt);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,1,0,-1};
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) {
                    long long cnt = 0;
                    dfs(grid,i,j,dr,dc,m,n,cnt);
                    if(cnt % k==0) ans++;
                }
            }
        }
        return ans;
    }
};