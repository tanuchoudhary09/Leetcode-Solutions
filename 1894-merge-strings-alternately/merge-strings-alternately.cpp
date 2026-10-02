class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        string ans = "";
        int n = min(len1, len2);
        for(int i = 0; i < n; i++) {
            ans += word1[i]; ans += word2[i];
        }
        if(len1 == len2) return ans;
        else if(len1 > len2) ans += word1.substr(len2);
        else ans += word2.substr(len1);
        return ans;
    }
};