class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++) pre[i][0] += grid[i][j];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m-2;j++){
                pre[i][j] = pre[i][j-1]-grid[i][j-1]+grid[i][j+2];
            }
        }
        int mx = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                mx = max(mx,pre[i][j]+pre[i+2][j]+grid[i+1][j+1]);
            }
        }

        return mx;
    }
};