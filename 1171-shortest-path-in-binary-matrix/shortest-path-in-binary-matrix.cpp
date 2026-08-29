class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        if(n==1 && m==1) return 1;
        queue<pair<pair<int,int>,int>>q;// dijkstra but with queue cz we will get the q elemenets in order
        //int ans = 0;
        q.push({{0,0},1});
        vector<int> dr = {1,-1,1,-1,0,0,1,-1};
        vector<int> dc = {1,1,-1,-1,-1,1,0,0};
        grid[0][0]=1;
        while(!q.empty()){
            auto top = q.front();
            int dis = top.second;
            int r = top.first.first;
            int c = top.first.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0) {
                    if(nr==n-1 && nc==m-1) return dis+1;
                    grid[nr][nc]=1;
                    q.push({{nr,nc},dis+1});
                }
            }
            
        }
        return -1;
    }
};