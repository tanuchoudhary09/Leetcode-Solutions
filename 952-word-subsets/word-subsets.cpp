class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(),m = words2.size();
        int mx[26]={0};
        for(int i=0;i<m;i++){
            int v[26] = {0};
            string t = words2[i];
            for(char c :t) v[c-'a']++;
            for(int i=0;i<26;i++){
                mx[i] = max(mx[i],v[i]);
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            int frq[26] = {0};
            string t = words1[i];
            for(char c :t) frq[c-'a']++;
            bool flag = true;
            for(int i=0;i<26;i++){
                if(frq[i]<mx[i]) {flag = false;break;}
            }
            if(flag) ans.push_back(t);
        }
        return ans;
    }
};