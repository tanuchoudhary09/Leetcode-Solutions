class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int,vector<bool>>mp;
        for(int i=0;i<m;i++){
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            if(!mp.count(r)) mp[r] = vector<bool>(11,false);
            mp[r][c] = true;//accesses the rth row and inserts true in the cth column
        }
        int count = (n-mp.size())*2;
        for(auto pair:mp){
            vector<bool>&v = pair.second;
            bool flag = false;
            if(!v[2] && !v[3] && !v[4] && !v[5] ){
                count++;
                v[2]=v[3]=v[4]=v[5]=true;
                flag =true;
            }
            if(!v[8] && !v[9] && !v[6] && !v[7] ){
                count++;
                v[8]=v[6]=v[9]=v[7]=true;
                flag=true;
            }
            if(!flag && v[6]!=1 && v[7]!=1 && v[4]!=1 && v[5]!=1 ){
               count++;
                v[6]=v[5]=v[4]=v[7]=true;
                //flag=true;
            }
        }
        return count;
    }
};