class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int cnt1 = 0;
        string ans ="";
        while(i<n && j<n){
            while(cnt1!=k && j<n){
                if(s[j]=='1') cnt1++;
                j++;
            }
            if(cnt1!=k) break;
            while(s[i]=='0') i++;
            string t = s.substr(i,j-i);
            if(ans.size()>t.size() || ans == "") ans = t;
            else if(ans.size()==t.size()) ans = (ans<t)?ans:t;
            if(s[i]=='1') cnt1--;
            i++;
        }
        return ans;
    }
};