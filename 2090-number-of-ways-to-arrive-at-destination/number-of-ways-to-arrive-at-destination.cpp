class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        typedef pair<long long,int> pr;
        long long mod = 1e9+7;
        vector<pr> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        dist[0] = 0;
        vector<long long>ways(n,0);
        ways[0] = 1;
        //int prev = INT_MAX;
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long u = it.first;
            int v = it.second;
            if(u>dist[v]) continue;
            for(auto adjnode : adj[v]){
                int v1 = adjnode.first;
                long long v2 = adjnode.second;
                if(v2+u<dist[v1]){
                    dist[v1] = v2+u;
                    ways[v1] = ways[v];
                    pq.push({dist[v1],v1});
                }
                // if(v1==n-1 && prev>v2) {
                //     prev = v2;
                //     ans = 1;
                //     //ans++;
                // }
                else if(u+v2 == dist[v1]){
                    //ans++;
                    ways[v1] = (ways[v1] + ways[v]) %mod;
                } 
            }
        }
        return ways[n-1]% mod;
    }
};