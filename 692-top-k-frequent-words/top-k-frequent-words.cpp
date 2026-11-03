class Solution {
    struct Compare {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto& s : words) m[s]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>pq;//instead of greater we make our own fn to store
        for(auto pr : m) {
            pq.push({pr.second,pr.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string>ans(k);
        int i = k-1;
        while(!pq.empty()) {
            auto pr = pq.top();
            pq.pop();
            ans[i--] = pr.second;
        }
        return ans;
    }
};