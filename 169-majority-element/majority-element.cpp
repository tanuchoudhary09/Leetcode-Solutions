class Solution {
public:
    //Boyer moore algo
    //works cz the ele is occuring n/2 so say:
    // If the array size is n = 7, the majority element must appear at least 4 times. That leaves at most 3 other elements.
    //Step 1: The 3 other elements pair up with 3 of the majority elements. They cancel each other out completely.
    //Step 2: The count drops to 0.
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(int num : nums){
            if(count == 0) ans = num;
            if(ans == num) count++;
            else count--;
        }
        return ans;
    }
};