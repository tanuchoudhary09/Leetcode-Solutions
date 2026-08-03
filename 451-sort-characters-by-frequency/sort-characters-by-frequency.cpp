bool cmp(pair<char, int> &a, const pair<char, int> &b){
    return a.second>b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<int>v(123,0);
        vector<pair<char,int>>fq;
        for(char c:s) v[c]++;
        for(int i = 48;i<123;i++){
            if(v[i]>0) fq.push_back({(char)i,v[i]});
        }
        sort(fq.begin(),fq.end(),cmp);
        string ans;
        for(auto x:fq){
            int l = x.second;
            int ch = x.first;
            ans.append(l, ch);
        }
        return ans;
    }
};