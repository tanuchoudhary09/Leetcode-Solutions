class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        stack<int>st;
        vector<int>v(m,-1);
        //st.push(-1);
        for(int i = m-1; i >= 0; i--){
            int num = nums2[i];
            while(st.size()>0 &&st.top()<=num) st.pop();
            if(st.size()==0) v[i] = -1;
            else v[i] = st.top();
            st.push(num);
        }
        unordered_map<int,int>mp;
        int i = 0;
        for(int num : nums2){ mp[num] = v[i];i++;}
        for(int i=0;i<n;i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};