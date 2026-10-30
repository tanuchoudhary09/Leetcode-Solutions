class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        for(int i = 0; i < n; i++){
            int initial = nums[i];
            string s = "";
            int cnt = 1;
            while(i < n-1 && nums[i]+1==nums[i+1]){
                i++;
                cnt++;
            }
            if(cnt==1){
                s += to_string(initial);
                ans.push_back(s);
                continue;
            }
            s+=to_string(initial);
            s+="->";
            s+=to_string(nums[i]);
            ans.push_back(s);
        }
        return ans;
    }
};