class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<int,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(m[s[i]]<m[s[i+1]]) {
                count += m[s[i+1]] - m[s[i]];
                i++;
            }
            else count+= m[s[i]];
        }
        //if(!(m[s[n-1]]<m[s[n-1-1]])) count += m[s[n-1]];
        return count;
    }
};