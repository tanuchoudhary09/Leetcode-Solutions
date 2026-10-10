class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        typedef long long ll;
        int n = nums1.size();
        int mx = 0;
        ll k = (long long) k1+k2;
        for(int i = 0; i < n; i++) mx = max(abs(nums1[i]-nums2[i]),mx);
        vector<long long>fq(mx+1,0);
        for(int i = 0; i < n; i++){
            int diff = abs(nums1[i]-nums2[i]);
            if(diff > 0) fq[diff]++;
        }
        for(int i = mx; i > 0 && k > 0; i--){
            if(fq[i]==0) continue;
            if(k>=fq[i]){
                fq[i-1] += fq[i];
                k -= fq[i];
                fq[i] = 0;
            }else{
                fq[i-1] += k;
                fq[i] -= k;
                k=0;
            }
        }
        ll ans = 0;
        for(ll i = 0; i <= mx; i++){
            if(fq[i] > 0){
                ans += fq[i] * i * i;
            }
        }
        return ans;
    }
};