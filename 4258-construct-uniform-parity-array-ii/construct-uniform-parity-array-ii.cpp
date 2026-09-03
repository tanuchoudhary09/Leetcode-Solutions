class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mn = INT_MAX;
        for(int x : nums1){
            if(x%2!=0) mn = min(mn,x);
        }
        if(mn==INT_MAX) return true;
        //std::cout<<mn;
        for(int x : nums1){
            if(x%2==0 && mn>=x) return false;
        }
        return true;

    }
};