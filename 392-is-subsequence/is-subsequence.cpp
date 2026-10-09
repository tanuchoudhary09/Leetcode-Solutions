class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = t.length(), n = s.length();
        while(i < n && j < m){
            if(s[i]==t[j]) i++;
            j++;
        }
        return n==i;
    }
};