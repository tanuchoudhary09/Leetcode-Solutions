class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length(), sz = spaces.size(), j = 0;
        string t = "", ans = "";
        for(int i = 0; i < n; i++){
            if(j < sz && spaces[j] == i){
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};