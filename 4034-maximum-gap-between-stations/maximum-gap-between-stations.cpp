class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();
        if(n == 1) return 0;
        vector<vector<int>>v;
        int j=0;
        for(int i=0;i<n;i++){
            for(;j<m;j++){
                if(skill[i]==station[j]){
                    v.push_back({j,-1});
                    j++;
                    break;
                }
            }
        }
        j = m-1;
        for(int i=n-1;i>=0;i--){
            for(;j<m;j--){
                if(skill[i]==station[j]){
                    v[i][1] = j;
                    j--;
                    break;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<v.size()-1;i++) ans = max(ans,v[i+1][1]-v[i][0]);
        return ans;
    }
};