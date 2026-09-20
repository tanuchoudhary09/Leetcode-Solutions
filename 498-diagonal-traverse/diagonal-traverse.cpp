class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>ans(m*n);
        int r = 0,c = 0;
        for(int i=0;i<n*m;i++){
            ans[i] = mat[r][c];
            if((r+c)%2==0){
                if(c==n-1) r++;
                else if(r==0) c++;
                else{
                    r--;
                    c++;
                }
            }else{
                if(r==m-1) c++;
                else if(c==0) r++;
                else{
                    c--;
                    r++;
                }
            }
            
        }
        return ans;
    }
};