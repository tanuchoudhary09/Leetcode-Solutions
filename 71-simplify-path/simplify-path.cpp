class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string>v;
        string ans = "";
        for(int i=0;i<n;i++){
            string t = "";
            if (path[i]=='/') continue;
            while(i<n && path[i]!='/'){
                t+=path[i];
                i++;
            }
            if(t==".") continue;
            if(t=="..") {
                if(v.size()) v.pop_back();
            }else v.push_back(t);
        }
        if(!v.size()) return "/";
        for(int i = 0;i<v.size();i++) ans+='/'+v[i];
        return ans;
    }
};