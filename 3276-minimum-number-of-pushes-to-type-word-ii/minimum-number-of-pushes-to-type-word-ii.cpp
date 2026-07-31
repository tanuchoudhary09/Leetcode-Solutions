class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26,0);
        int count = 0, h = 0;
        for(char c :word) v[c-'a']++;
        sort(v.begin(),v.end());
        int n = 1;
        for(int i=25;i>=0;i--){
            if(v[i]!=0) h++;
            if(h==9){
                n++;h=1;
            }
            count += n*v[i];
        }
        return count;
    }
};