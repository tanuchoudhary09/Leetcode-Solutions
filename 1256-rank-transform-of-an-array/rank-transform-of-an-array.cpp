class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>v = arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>m;
        int k = 1;
        for(int i=0;i<n;i++){
            if(!m.count(arr[i])) {m[arr[i]]=k;k++;}
        }
        for(int i=0;i<n;i++){
            v[i]=m[v[i]];
        }
        return v;
    }
};