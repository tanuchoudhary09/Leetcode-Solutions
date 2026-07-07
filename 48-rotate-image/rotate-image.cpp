class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // int m = matrix.size();
        // int n = matrix[0].size();
        // for (int i = 0; i < m; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int temp = matrix[i][j];
        //         matrix[i][j] = matrix[j][i];
        //         matrix[j][i] = temp;
        //     }
        // }
        // for (int k = 0; k < n ; k++) {
        //     for (int i=0,j=n-1;i<=j;i++,j--) {
        //         int temp = matrix[k][j];
        //         matrix[k][j] = matrix[k][i];
        //         matrix[k][i] = temp;
        //     }
        // }
        int n = mat.size();
        vector<vector<int>> transformedMatrix(n,vector<int>(n));
        vector<vector<int>> supportingMatrix(n,vector<int>(n));
        
        supportingMatrix = mat;
        
            mat = supportingMatrix;
            for(int i=0,a=0;i<n;i++,a++){
                for(int j=n-1,b=0;j>=0;j--, b++){
                    transformedMatrix[a][b] = mat[j][i];
                    supportingMatrix[a][b] = transformedMatrix[a][b];
                }
            }
        mat = transformedMatrix;
    }
};
