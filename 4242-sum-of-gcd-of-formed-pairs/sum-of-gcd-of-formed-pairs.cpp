class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int rem = a%b;a=b;b=rem;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = INT_MIN;
        long long sum = 0;
        for(auto &num :nums){
            mx = max(mx,num);
            num = gcd(mx,num);
        }
        sort(nums.begin(),nums.end());
        int i = 0, j = n - 1;
        while(i<j){
            sum+=(gcd(nums[i],nums[j]));
            i++;
            j--;
        }
        return sum;
    }
};