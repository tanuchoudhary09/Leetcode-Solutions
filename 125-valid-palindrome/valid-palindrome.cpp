class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(j>i){
            while( j > i && !isalnum(s[i])) i++;
            while( j > i && !isalnum(s[j])) j--;//alnum fn
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
            if(s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] + 32;
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};