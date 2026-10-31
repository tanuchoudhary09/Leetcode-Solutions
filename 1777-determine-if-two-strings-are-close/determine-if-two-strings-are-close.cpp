class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>fq1(26,0),fq2(26,0);
        int m = word1.length();
        int n = word2.length();
        if(n!=m) return false;
        for(int i = 0; i < m; i++) fq1[word1[i]-'a']++;
        for(int i = 0; i < n; i++) fq2[word2[i]-'a']++;
        for(int i = 0; i < 26; i++){
            if(fq1[i]==0 && fq2[i]!=0) return false;
            if(fq1[i]!=0 && fq2[i]==0) return false;
        }
        sort(fq1.begin(),fq1.end());
        sort(fq2.begin(),fq2.end());
        for(int i = 0; i < 26; i++){
            if(fq1[i]!=fq2[i]) return false;
        }
        return true;
    }
};