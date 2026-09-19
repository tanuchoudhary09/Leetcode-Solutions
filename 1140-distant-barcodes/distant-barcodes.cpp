class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int>ans(n);
        unordered_map<int,int>m;
        for(int x : barcodes) m[x]++;
        priority_queue<pair<int,int>>mx;
        for(auto x : m) mx.push({x.second,x.first});
        int i=0;
        //int j=0;
        while(!mx.empty()){
            int a = mx.top().first,b=mx.top().second;
            mx.pop();
            while(a){
                if(i>=n) i =1;
                ans[i] = b;
                i+=2;
                a--;
            }

        }
        return ans;
    }
};