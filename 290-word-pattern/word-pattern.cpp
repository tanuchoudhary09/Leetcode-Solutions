class Solution {
public:
    bool wordPattern(string pattern, string s){
        int n = pattern.length(),k = s.length(),i=0,j=0;
        unordered_map<char,string>m;
        unordered_map<string,char>m1;
        while(j<k){
            string t="";
            while(j<k && s[j]!=' ') {
                t+=s[j++];
            }
            std::cout<<t;
            j++;
            if(i>=n) return false;
            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=t) return false;
            }else m[pattern[i]]=t;
            if(m1.find(t)!=m1.end()){
                if(m1[t]!=pattern[i]) return false;
            }else m1[t]=pattern[i];
            i++; 
        }
        return i==n;
    }
};