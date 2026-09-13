class disjointset{
public:
    vector<int>rank,size,parent;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
            size[i] = i;
        }
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
            parent[up_v] = up_v;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjointset ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1) ds.unionBySize(i,j);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i) cnt++;
        }
        return cnt;
    }
};