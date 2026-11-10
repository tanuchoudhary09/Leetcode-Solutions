class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,INT_MAX);
        int ans=0;
        vector<pair<int,int>>adj[n+1];
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,k});
        time[k]=0;
        int sz=times.size();
        for(int i=0;i<sz;i++) adj[times[i][0]].push_back({times[i][2],times[i][1]});
        while(q.size()){
            int wt=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto k:adj[node]){
                if(k.first+wt<time[k.second]) {
                    time[k.second]=k.first+wt;
                    q.push({k.first+wt,k.second});
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans=max(time[i],ans);
            if(time[i]==INT_MAX) return -1;
        }
        return ans;
    }
};