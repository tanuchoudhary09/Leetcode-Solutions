class Solution {
public:
    int minSteps(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        vector<int>freq1(26,0),freq2(26,0);
        for(int i=0;i<l1;i++) freq1[s[i]-'a']++;
        for(int i=0;i<l2;i++) freq2[t[i]-'a']++;
        int ans = 0;
        for(int i=0;i<26;i++) ans+=abs(freq1[i]-freq2[i]);
        return ans;
    }
};