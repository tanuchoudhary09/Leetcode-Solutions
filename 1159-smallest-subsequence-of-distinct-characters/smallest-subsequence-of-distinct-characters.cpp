class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int>v(26);
        vector<bool>flag(26,false);
        string ans;
        for(int i=0;i<n;i++) v[s[i]-'a']=i;
        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            if(flag[idx]==true) continue;
            while(ans.length()>0 && ans.back()>s[i] && v[ans.back()-'a']>i){
                flag[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            flag[idx]=true;
        }
        return ans;
    }
};