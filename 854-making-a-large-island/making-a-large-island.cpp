class disjointset{
public:
    vector<int>rank,size,parent;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0;i<=n;i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if(up_u == up_v) return;
        if(rank[up_u]<rank[up_v]) parent[up_u] = up_v;
        else if(rank[up_u]>rank[up_v]) parent[up_v] = up_u;
        else{
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if(up_u == up_v) return;
        if(size[up_u]<size[up_v]){
            parent[up_u] = up_v;
            size[up_v]+=size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u]+=size[up_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();   
        disjointset ds(n*n); 
        int mx = INT_MIN;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};
        //vector<vector<int,int>> vst;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if( nr>=0 && nc>=0 &&  nr<n && nc<n && grid[nr][nc] == 1) ds.unionBySize(i*n+j,nr*n+nc);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                set<int>comp;
                for(int k = 0; k < 4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if( nr>=0 && nc>=0 &&  nr<n && nc<n && grid[nr][nc] == 1) comp.insert(ds.findUPar(nr*n + nc));
                }
                int sz = 1;
                for(auto it : comp) sz += ds.size[it];
                mx = max(mx,sz);
            }
        }
        for(int i = 0; i < n*n; i++)mx = max(mx,ds.size[ds.findUPar(i)]);// if all 1s are there the second loop wont run giving INT_MAX as the output(tc-3)
        return mx;
    }
};