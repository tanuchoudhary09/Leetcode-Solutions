//tarjan's algo
class Solution {
    int time = 1;
public:
    void dfs(int node, int parent, vector<int> &vst, vector<int> adj[], vector<int>&tin, vector<int>&lo, vector<vector<int>>&ans){
        vst[node] = 1;
        tin[node] = lo[node] = time;
        time++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vst[it]){
                dfs(it,node,vst,adj,tin,lo,ans);
                lo[node] = min(lo[node],lo[it]);
                if(lo[it]>tin[node]) ans.push_back({node,it});
            }
            else lo[node] = min(lo[node], lo[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<vector<int>>ans;
        vector<int>vst(n,0);
        for(auto it : connections){ 
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>tin(n),lo(n);
        dfs(0,-1,vst,adj,tin,lo,ans);
        return ans;
    }
};