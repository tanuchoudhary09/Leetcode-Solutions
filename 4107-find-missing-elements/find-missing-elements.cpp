class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = INT_MIN,mn = INT_MAX;
        unordered_set<int>s;
        for(int x : nums){
            mx = max(mx,x);
            mn = min(mn,x);
            s.insert(x);
        }
        vector<int>ans;
        for(int i=mn+1;i<mx;i++){
            if(!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};