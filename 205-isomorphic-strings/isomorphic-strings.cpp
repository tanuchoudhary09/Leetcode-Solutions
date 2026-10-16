class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<int,int>m1,m2;
        for(int i = 0; i < n; i++){
            if(m1.count(s[i]) && m1[s[i]] != t[i]) return false;
            m1[s[i]] = t[i];
            if(m2.count(t[i]) && m2[t[i]] != s[i]) return false;
            m2[t[i]] = s[i];
        }
        return true;

    }
};
