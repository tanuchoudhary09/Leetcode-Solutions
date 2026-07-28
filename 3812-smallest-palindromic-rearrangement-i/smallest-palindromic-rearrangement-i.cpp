class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string t = "";
        char c=-1;
        vector<int>v(26,0);
        for(char c:s) v[c-'a']++;
        for(int i=0;i<26;i++){
            if(v[i]%2!=0) {
                c = 'a'+i;
                v[i]--;
            }
            for(int j=0;j<v[i]/2;j++) t+='a'+i;
            
        }
        string help = t;
        reverse(help.begin(),help.end());
        
        if(c!=-1) return t+c+help;
        return t+help;
    }
};