class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx1= INT_MIN,mx2=mx1;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x>=mx1){
                mx2=mx1;mx1=x;
            }else if(x>mx2 ){
                mx2=x;
            }
        }
        return (mx1-1)*(mx2-1);
    }
};