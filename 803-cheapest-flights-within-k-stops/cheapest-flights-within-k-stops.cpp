class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        typedef pair<int,int> pr;
        vector<pr>adj[n];
        for(auto it : flights) adj[it[0]].push_back({it[1],it[2]});
        queue<pair<int,pr>>q;
        q.push({0,{src,0}});;
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int a = val.first;
            int b = val.second.first;
            int c = val.second.second;
            if(a>k) continue;
            for(auto it : adj[b]){
                int v1 = it.first;
                int v2 = it.second;
                if(v2+c<dist[v1] && a<=k) {
                    dist[v1] = v2+c;
                    q.push({a+1,{v1,c+v2}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};