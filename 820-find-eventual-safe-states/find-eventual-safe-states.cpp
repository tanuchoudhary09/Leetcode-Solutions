class Solution {
public:
    //using topo and bfs
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int> indegree(n,0);
        vector<int>topo;
        for(int i=0;i<n;i++){
            for(auto edge:graph[i]){
                adj[edge].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        //int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};