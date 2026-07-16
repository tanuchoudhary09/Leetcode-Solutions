class NumMatrix {
public:
    vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& matrix) {
        v = matrix;
        int n = matrix[0].size(), m = matrix.size();
        for(int i=0;i<m;i++){
            long long sum = 0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
                v[i][j] = (int)sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long ans=0;
        if(!col1){
            for(int i=row1;i<=row2;i++){
                ans+=v[i][col2];
            }
            return ans;
        }else{
            for(int i=row1;i<=row2;i++){
                ans+=v[i][col2]-v[i][col1-1];
            }
            return ans;
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */