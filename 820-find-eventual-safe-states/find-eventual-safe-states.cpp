class Solution {
public:
    bool dfs(int r,vector<vector<int>>&graph,vector<int>&check,vector<int>&path,vector<int>&vst){
        vst[r] = 1;
        path[r] = 1;
        check[r] = 0;
        for(auto it: graph[r] ){
            if(!vst[it]) {
                if(dfs(it,graph,check,path,vst)) return true;
            }
            else if(path[it]) return true;
        }
        check[r] = 1;
        path[r] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vst(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!vst[i]) dfs(i,graph,check,path,vst);
            //if(!vst[i][1]) dfs();
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};