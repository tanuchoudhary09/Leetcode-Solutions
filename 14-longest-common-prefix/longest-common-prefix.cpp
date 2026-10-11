class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string ans = "";
        string s = strs[0], t = strs[n-1];
        int l1 = s.length(), l2 = t.length();
        for(int i=0;i<min(l1,l2);i++){
            if(s[i]==t[i]) ans += s[i];
            else break;
        }
        return ans;
    }
};