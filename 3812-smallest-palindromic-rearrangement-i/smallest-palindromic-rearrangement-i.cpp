class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        sort(s.begin(),s.end());
        vector<int>v(26,0);
        for(char c:s) v[c-'a']++;
        int j = 0,k = n-1;
        for(int i=0;i<26;i++){
            if(v[i]%2!=0) {
                s[n/2]='a'+i;
                v[i]--;
                i--;
            }
            else {
                while(v[i]>0){
                    s[j]='a'+i;
                    s[k]='a'+i;
                    j++;k--;
                    v[i]-=2;
                }
            }
        }
        // string help = t;
        // reverse(help.begin(),help.end());
        // t +=help;
        // if(c!=-1) t+=c;
        // return t;
        return s;
    }
};