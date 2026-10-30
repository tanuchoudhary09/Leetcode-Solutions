class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it : edges) adj[it[0]].push_back({it[1],it[2]});
        long long inf = LLONG_MAX;
        vector<vector<long long>>dist(n,vector<long long>(k+1,LLONG_MAX));
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        dist[0][1] = 0;
        pq.push({0, 0*(k+1) +1});
        while(!pq.empty()){
            long long d = pq.top().first;
            int state = pq.top().second;
            pq.pop();
            int u = state/(k+1);
            int cnt = state%(k+1);
            if(u==n-1) return d;
            if(d > dist[u][cnt]) continue;
            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;
                int next_cnt = (labels[u]==labels[v])? cnt +1:1;
                if(next_cnt<=k && d+w<dist[v][next_cnt]) {
                    dist[v][next_cnt] = d+w;
                    int next_state = v*(k+1) +next_cnt;
                    pq.push({dist[v][next_cnt],next_state});
                }
            }
        }
        return -1;
    }
};