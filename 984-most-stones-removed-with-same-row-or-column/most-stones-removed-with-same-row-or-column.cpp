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
    int removeStones(vector<vector<int>>& stones) {
        int nRows = 0;
        int nCols = 0;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            nRows = max(nRows,stones[i][0]);
            nCols = max(nCols,stones[i][1]);
        }
        disjointset ds(nRows+nCols+1);
        unordered_set<int>s; // we can use a vector bool and iterate through stones
        for(auto it : stones){
            int nodeR = it[0];
            int nodeC = it[1] + nRows +1;
            ds.unionBySize(nodeR,nodeC);
            s.insert(nodeR);
            s.insert(nodeC);
        }
        int cnt = 0;
        for(auto it : s){
            if(ds.findUPar(it)==it) cnt++;
        }
        return n - cnt;
    }
};