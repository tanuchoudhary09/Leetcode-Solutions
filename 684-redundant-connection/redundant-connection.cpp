class Solution {
public:
    void check(int r,int t,vector<vector<int>>&adj,vector<int>&vst,vector<int>&ans,int u, int v){
        vst[r] = 1;
        queue<int>q;
        q.push(r);
        while(!q.empty()){
            int node = q.front();

            q.pop();
            if(node == t){
                ans = {u,v};
                return;
            }
            for(auto adjNode : adj[node]){
                if(!vst[adjNode]){
                    vst[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //int m = edges[0].size();
        vector<vector<int>>adj(n+1);
        //vector<int>vst(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            vector<int>vst(n+1,0);
            
            check(u,v,adj,vst,ans,u,v);
            if(!ans.empty()) return ans;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        return {};
    }
};