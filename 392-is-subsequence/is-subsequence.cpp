class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n =s.length(),m=t.length(),i=0,j=0,idx=INT_MIN;
        while(j<m && i<n){
            if(s[i]==t[j]){
                if(idx>i) return false;
                idx = i;
                i++;
            }
            j++;
        }
        if(i!=n) return false;
        return true;
    }
};