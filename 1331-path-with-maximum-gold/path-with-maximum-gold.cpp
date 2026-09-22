class Solution {
public:
    int dfs(vector<vector<int>>&grid,int r,int c,vector<int>&dr,vector<int>&dc){
        //vst[r][c] = 1;
        int mx = 0;
        int prev = grid[r][c];
        grid[r][c] = 0;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]) {
                mx = max(dfs(grid,nr,nc,dr,dc),mx);
                //std::cout<<val;
                //dfs(grid,val,nr,nc);
            }
        }
        grid[r][c] = prev;
        return prev + mx;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,-1,0,1};
        //vector<vector<int>>vst(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = 0;
                if(grid[i][j]) ans = max(ans,dfs(grid,i,j,dr,dc));
            }
        }
        return ans;
    }
};