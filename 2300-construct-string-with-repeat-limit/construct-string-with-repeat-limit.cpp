
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        vector<int>v(26,0);
        priority_queue<pair<char,int>>pq;
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        for(int i=0;i<26;i++){
            if(v[i]>0){
                char c = 'a'+i;
                pq.push({c,v[i]});
            }
        }
        string ans = "";
        while(!pq.empty()){
            pair<char,int> mx1 = pq.top();
            pq.pop();
            int len = min(mx1.second,repeatLimit);
            for(int i=0;i<len;i++) ans+=(mx1.first);
            pair<char,int> mx2;
            if(mx1.second-len>0){
                if(pq.empty()) return ans;
                mx2=pq.top();
                pq.pop();
                ans+=mx2.first;
                if(mx2.second-1>0) pq.push({mx2.first,mx2.second-1});
                pq.push({mx1.first,mx1.second-len});
            }
            
        }
        return ans;
    }
};