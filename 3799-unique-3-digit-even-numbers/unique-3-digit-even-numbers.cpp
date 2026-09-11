class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int count = 0;
        vector<int>fq(10,0);
        for(int x : digits) fq[x]++;
        for(int i=100;i<=998;i+=2){
            int a = i/100;
            int b = (i/10)%10;
            int c = i%10;
            vector<int>v(10,0);
            v[a]++;v[b]++;v[c]++;
            if(fq[a]>=v[a] && fq[b]>=v[b] && fq[c]>=v[c]) count++;
        }

        return count;
    }
};