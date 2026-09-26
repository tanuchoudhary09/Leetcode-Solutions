class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        string ans = "";
        unordered_map<string,string>m;
        for(auto it : knowledge) m[it[0]] = it[1];
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string t = "";
                while(s[i]!=')') {
                    t+=s[i];
                    i++;
                }
                if(m.count(t)) ans += m[t];
                else ans += '?';
            }else ans += s[i];
        }
        return ans;
    }
};