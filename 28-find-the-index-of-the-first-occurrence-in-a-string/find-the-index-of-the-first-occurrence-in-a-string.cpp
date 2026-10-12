class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if(n > m) return -1;
        int i = 0;
        while(i <= m-n){
            string t = haystack.substr(i,n);
            if(t==needle) return i;
            i++;
        }
        return -1;
    }
};