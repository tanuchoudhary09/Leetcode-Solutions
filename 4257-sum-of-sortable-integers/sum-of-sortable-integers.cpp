class Solution {
public:
    bool check(vector<int>& nums, vector<int>& num, int& k){
        int n = nums.size();
        for(int i = 0; i < n; i+=k){
            vector<int>got(nums.begin() + i, nums.begin() + i + k);
            vector<int>srch(num.begin() + i, num.begin() + i + k);
            int pvt = 0;
            if(got[0] < got[k-1]) pvt++;
            for(int j = 0; j < k - 1; j++){
                if(got[j] > got[j+1]) pvt++;
                if(pvt > 1) return false;
            }
            sort(got.begin(),got.end());
            for(int j = 0; j < k ; j++){
                if(got[j] != srch[j]) return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> num = nums;
        sort(num.begin(),num.end());
        for(int k = 1; k <= n; k++){
            if(n % k == 0 && check(nums,num,k)) ans += k;
        }
        //check(nums,num,n);
        return ans;
        
    }
};