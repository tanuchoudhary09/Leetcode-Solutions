class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0),v2(26,0);
        int m = s1.length(),n = s2.length();
        if(m>n) return false;
        for(int i=0;i<m;i++) {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        for(int i=0;i<n-m;i++){
            if(v1==v2) return true;
            v2[s2[i]-'a']--;
            v2[s2[i+m]-'a']++;
        }
        return v1==v2;
    }
};