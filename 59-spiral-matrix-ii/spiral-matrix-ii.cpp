class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int a = 0;
        int k = 1;
        int r=n,c=n;
        while(1){
            for(int i=a;i<c;i++){
                matrix[a][i]= k;
                k++;
                if(k>n*n) break;
            }
            if(k>n*n) break;
            for(int i=a+1;i<r;i++){
                matrix[i][c-1]= k;
                k++;
                if(k>n*n) break;
            }
            if(k>n*n) break;
            for(int i=c-2;i>=a;i--){
                matrix[r-1][i]= k;
                k++;
                if(k>n*n) break;
            }
            if(k>n*n) break;
            for(int i=r-2;i>=a+1;i--){
                matrix[i][a]= k;
                k++;
                if(k>n*n) break;
            }
            if(k>n*n) break;
            r--;
            c--;
            a++;
        }
        return matrix;
    }
};