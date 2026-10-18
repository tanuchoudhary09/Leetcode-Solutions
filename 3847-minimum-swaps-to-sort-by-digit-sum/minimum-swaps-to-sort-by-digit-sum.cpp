class Solution {
public:
    long long digsum(int x, long long sum){
        while(x > 0){
            sum += x%10;
            x = x/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>m1;
        unordered_map<int,int>m2;
        for(int i = 0; i < n; i++) {
            m1.push_back({digsum(nums[i],0),nums[i]});
            m2[nums[i]] = i; 
        }
        sort(m1.begin(),m1.end());
        int i = 0;
        int count = 0;
        for(auto x : m1){
            if(m2[x.second]!=i){
                int idx = m2[x.second];
                swap(nums[i],nums[m2[x.second]]);
                m2[nums[m2[x.second]]] = idx;
                m2[nums[i]] = i;
                count++;
            }
            i++;
        }
        return count;
    }
};