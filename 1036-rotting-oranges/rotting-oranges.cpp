class Solution {
public:
    void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid,vector<vector<int>>&vst,int &cnt,int &fresh){
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            bool flag = false;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int a = q.front().first,b=q.front().second;q.pop();
                for(int p=-1;p<=1;p++){
                    for(int k=-1;k<=1;k++){
                        int r = a+p,c=b+k;if(abs(p) + abs(k) != 1) continue;
                        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && (!vst[r][c])){
                            vst[r][c] = 1;
                            fresh--;
                            flag = true;
                            q.push({r,c});
                        
                        }
                    }
                    
                }
            }
            if(flag) cnt++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0,fresh = 0;
        vector<vector<int>>vst(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 ) {
                    q.push({i,j});
                    vst[i][j]=1;
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        bfs(q,grid,vst,cnt,fresh);
        if(fresh>0) return -1;
        return cnt;
    }

};