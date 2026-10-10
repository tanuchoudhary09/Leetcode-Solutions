class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>fq(n+1,0);
        for(int i=0;i<n;i++){
            if(citations[i]>=n) fq[n]++;
            else fq[citations[i]]++;
        }
        int papers = 0;
        for(int i=n;i>=0;i--){
            papers += fq[i];
            if(papers>=i) return i;
        }
        return 0;
    }
};