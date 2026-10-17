class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        int m = s.length();
        vector<string>t;
        string temp;
        for(int i = 0; i < m; i++){
            temp = "";
            while(i < m && s[i]!=' ') {
                temp += s[i];
                i++;
            }
            t.push_back(temp);
            
        }
        if(t.size()!=n) return false;
        unordered_map<char,string>m1;
        unordered_map<string,char>m2;
        for(int i = 0; i < n; i++){
            if(m1.count(pattern[i]) && m1[pattern[i]] != t[i]) return false;
            m1[pattern[i]] = t[i];
            if(m2.count(t[i]) && m2[t[i]] != pattern[i]) return false;
            m2[t[i]] = pattern[i];
        }
        return true;
    }
};