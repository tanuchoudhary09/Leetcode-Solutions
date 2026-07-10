class Solution {
public:
//boyer moore algo extends to finding out n/k times majority ele-> O(1)spacelineratime
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(),t=n/3,count1=0,count2=0,ele1=0,ele2=0;
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (ele1== num)count1++;
            else if (ele2== num) count2++;
            else if (count1==0) ele1=num,count1=1;
            else if (count2==0) ele2=num,count2=1;
            else{
                count1--;count2--;
            }
        }
        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]) count1++;
            else if(ele2==nums[i]) count2++;
        }
        if(count1>t) ans.push_back(ele1);
        if(count2>t) ans.push_back(ele2);

        return ans;
    }
};