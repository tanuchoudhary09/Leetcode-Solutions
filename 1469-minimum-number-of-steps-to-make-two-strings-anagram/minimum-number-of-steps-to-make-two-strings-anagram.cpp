class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        int cnt = 0;
        vector<int>freq1(26,0),freq2(26,0);
        for(int i = 0; i < n; i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) cnt += abs(freq1[i]-freq2[i]);
        return cnt/2;
    }
};