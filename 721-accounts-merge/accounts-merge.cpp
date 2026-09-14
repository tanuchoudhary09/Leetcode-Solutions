// we can use maps and DSU, how to implement??
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointset ds(n);
        unordered_map<string,int>mp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()) mp[accounts[i][j]] = i;
                else ds.unionBySize(i, mp[accounts[i][j]]);
            }
        }
        vector<string>mgmail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mgmail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i = 0; i < n; i++){
            if(mgmail[i].size() == 0) continue;
            vector<string>temp;
            sort(mgmail[i].begin(),mgmail[i].end());
            temp.push_back(accounts[i][0]);
            for(auto it : mgmail[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};