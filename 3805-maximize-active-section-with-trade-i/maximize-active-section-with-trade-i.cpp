class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1"+s+"1";
        int n = t.length();
        vector<pair<int,int>>v;
        int i = 0,count = -2;
        while(i<n){
            int j = i+1;
            while(j<n && t[i]==t[j]) j++;
            v.push_back({i,j});
            i=j;
        }
        for(char c:t){
            if(c=='1') count++;
        }
        int mx = 0;
        for(int i=1;i<v.size()-1;i++){
            //int sum1=0,sum2=0;
            if(t[v[i].first]=='1'){
                int sum1 = v[i-1].second-v[i-1].first;
                int sum2 = v[i+1].second-v[i+1].first;
                mx = max(mx,sum1+sum2);
            }
            
        }
        return (int)count+mx;

        //return ans;
    }
};