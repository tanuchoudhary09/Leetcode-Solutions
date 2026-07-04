class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> transformedMatrix(n,vector<int>(n));
        vector<vector<int>> supportingMatrix(n,vector<int>(n));
        int k = 0;
        supportingMatrix = mat;
        while(k<4){
            bool flag = true;
            mat = supportingMatrix;
            for(int i=0,a=0;i<n;i++,a++){
                for(int j=n-1,b=0;j>=0;j--, b++){
                    transformedMatrix[a][b] = mat[j][i];
                    supportingMatrix[a][b] = transformedMatrix[a][b];
                    if(transformedMatrix[a][b]!= target[a][b]) flag=false;
                }
            }
            if(flag) return true;
            k++;
        }
        return false;
    }
};