class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int len1 = word1.length(), len2 = word2.length();
        string ans = "";
        while(i < len1 && j < len2){
            ans += word1[i];
            i++;
            ans += word2[j];
            j++;
        }
        while(i < len1){
            ans += word1[i];
            i++;
        }
        while(j < len2){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};