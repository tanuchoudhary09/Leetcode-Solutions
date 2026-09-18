class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        unordered_set<int>s1,s2;
        stack<int>st;
        for(int i=0;i<n;i++) st.push(arr[n-i-1]);
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            bool flag = true;
            s1.insert(st.top());
            st.pop();
            s2.insert(arr[i]);
            for(auto x : s1){
                if(!s2.count(x)) flag =false;
            }
            if(flag) count++;
        }
        return count;
    }
};