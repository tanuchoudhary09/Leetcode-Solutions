class Solution {
public:
    int maxDifference(string s) {
        int n = s.length(),x1=INT_MIN,x2=INT_MAX;
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]%2!=0) x1=max(x1,v[i]);
            else if(v[i]!=0)x2=min(x2,v[i]);
        }
        return x1-x2;
    }
};