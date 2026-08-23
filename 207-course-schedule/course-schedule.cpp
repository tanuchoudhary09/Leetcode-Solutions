class Solution {
public:
    //topo sort algo
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int> indegree(numCourses,0);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return cnt==numCourses;
    }
};