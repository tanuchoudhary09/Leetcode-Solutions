class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int sz = spaces.size();
        int j = 0;
        string t = "";
        string ans = "";
        for(int i = 0; i < n; i++){
            if(j < sz && spaces[j] == i){
                ans += t;
                ans += ' ';
                t = "";
                j++;
            }
            t += s[i];
        }
        ans += t;
        return ans;
    }
};