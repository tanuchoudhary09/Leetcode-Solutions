class Solution {
public:
//pop ans push
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            int idx = i%n;
            while(st.size()>0 && nums[idx]>=st.top()) st.pop();
            if(st.size()!=0) ans[idx]=st.top();
            st.push(nums[idx]);
        }
        // for(int i=0;i<n-1;i++){
        //     if(nums[n-1]<nums[i]) {
        //         nums1[n-1] = nums[i];
        //         break;
        //     }
        // }
        return ans;
    }
};