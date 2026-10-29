class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>fq(26,0);
        if(s.length()!=t.length()) return false;
        int n = s.length();
        for(int i = 0; i < n; i++){
            fq[s[i]-'a']++;
            fq[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(fq[i]!=0) return false;
        }
        return true;
    }
};