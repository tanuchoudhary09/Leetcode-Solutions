class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int len = INT_MIN;
        unordered_map<int,int>m;
        //for(char c:s) v[c-'a']++;
        while(j<n){
            m[s[j]]++;
            while(m[s[j]]>2){
                m[s[i]]--;
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};