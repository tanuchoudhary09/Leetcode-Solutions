class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>distance(n,vector<int>(m,0));
        vector<vector<int>>vst(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vst[i][j]=1;;
                }
            }
        }
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            distance[a][b] = dis;
            for(int i=0;i<4;i++){
                int nr = a + row[i];
                int nc = b + col[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !(vst[nr][nc])){
                    q.push({{nr,nc},dis+1});
                    vst[nr][nc]=1;
                }
            }
        }
        return distance;
    }
    
};