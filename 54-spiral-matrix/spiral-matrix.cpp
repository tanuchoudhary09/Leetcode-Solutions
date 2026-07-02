class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>v;
        int k = r*c;
        int a =0;
        while(1){
            for(int i=a;i<c;i++){
                v.push_back(matrix[a][i]);
            }
            if(v.size()==k) break;
            for(int i=a+1;i<r;i++){
                v.push_back(matrix[i][c-1]);
            }
            if(v.size()==k) break;
            for(int i=c-2;i>=a;i--){
                v.push_back(matrix[r-1][i]);
            }
            if(v.size()==k) break;
            for(int i=r-2;i>=a+1;i--){
                v.push_back(matrix[i][a]);
            }
            if(v.size()==k) break;
            r--;
            c--;
            a++;
        }
        return v;
    }
};