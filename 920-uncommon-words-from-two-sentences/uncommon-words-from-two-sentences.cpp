class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        int n = s1.length(),m = s2.length();
        string t="";
        for(int i=0;i<n;i++){
            t="";
            while(i<n && s1[i]!=' ') {
                t+=s1[i];i++;
            }
            mp[t]++;
        }
        for(int i=0;i<m;i++){
            t="";
            while(i<m && s2[i]!=' ') {
                t+=s2[i];i++;
            }
            mp[t]++;
        }
        vector<string>v;
        for(auto x:mp) {if(x.second==1) v.push_back(x.first);}
        return v;
    }
};