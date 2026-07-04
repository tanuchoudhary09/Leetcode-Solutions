class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        for(int i=0;i<n;i++){
            char c = s[i];
            if(m[c]<=1) return i;
        }
        return -1;
    }
};