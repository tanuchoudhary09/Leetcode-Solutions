class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string t = strs[0];
        for(int i = 0; i < n; i++){
            string s = strs[i];
            int l1 = s.length(), l2 = t.length();
            string temp = "";
            for(int i=0;i<min(l1,l2);i++){
                if(s[i]==t[i]) temp += s[i];
                else break;
            }
            t = temp;
        }
        return t;
    }
};