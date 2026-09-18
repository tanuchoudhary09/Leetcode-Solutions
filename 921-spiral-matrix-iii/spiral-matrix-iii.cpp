class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rS, int cS) {
        vector<vector<int>>ans;
        int n = rows*cols;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        int dir = 0,steps=1;
        ans.push_back({rS,cS});
        while(ans.size()<n){
            for(int i=0;i<2;i++){//two step each, 11 then 22 then 33
                for(int j=0;j<steps;j++){
                    //steps increase as stated above;
                    rS += dr[dir];
                    cS += dc[dir];//since we wanna walk in the same direction steps number of times
                    if(rS>=0 && rS<rows && cS>=0 && cS<cols){
                        ans.push_back({rS,cS});
                        if(ans.size()==n) return ans;
                    }
                }
                dir = (dir+1)%4; //converge and keep clock
            }
            steps++;
        }
        return ans;
    }
};