class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int> &vst){
        vst[node]=1;
        for(auto it:adj[node]){
            if(!vst[it]) dfs(it,adj,vst);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int>adj[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vst(N,0);int cnt = 0;
        for(int i=0;i<N;i++){
            if(!vst[i]){
                cnt++;
                dfs(i,adj,vst);
                
            }
        }
        return cnt;
    }
};