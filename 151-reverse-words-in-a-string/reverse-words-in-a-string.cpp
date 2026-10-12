class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n-1;
        int j;
        string t;
        string ans = "";
        while(i>=0){
            t = "";
            while(i >= 0 && s[i]==' ') i--;
            if(i < 0) break;
            j = i;
            while(j >= 0 && s[j]!=' ') {
                t += s[j];
                j--;
            }
            i = j;
            reverse(t.begin(),t.end());
            ans += t;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};