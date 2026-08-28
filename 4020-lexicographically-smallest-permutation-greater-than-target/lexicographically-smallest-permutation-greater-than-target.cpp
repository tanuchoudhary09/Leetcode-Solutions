class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> m(26,0);
        string ans;
        for(char c : s) m[c-'a']++;
        int a = 0;
        while(a<n && m[target[a]-'a']>0){
            m[target[a]-'a']--;
            a++;
        }
        int st = (a<n)? a : n-1;
        for(int i=st;i>=0;i--){
            if(i<a) m[target[i]-'a']++;
            int idx = -1;
            char c = target[i];
            for(int i=c-'a'+1;i<26;i++){
                if(m[i]>0){
                    idx = i;
                    break;
                }
            }
            if(idx!=-1){
                m[idx]--;
                ans = target.substr(0,i);
                ans += char('a'+idx);
                for(int i=0;i<26;i++) ans.append(m[i],char('a'+i));//appends ch as many times as it has repeated
                return ans;
            }
        }
        return "";
    }
};