class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i=0,j=n-1;
        int mx=INT_MIN;
        while(i<j){
            int mn = min(height[i],height[j]);
            mx = max(mn*(j-i),mx);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return mx;
    }
};