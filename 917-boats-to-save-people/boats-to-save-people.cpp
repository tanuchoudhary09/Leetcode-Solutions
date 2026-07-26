class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int ans = 0;
        int j = n-1,i = 0;
        while(i<=j){
            int a = people[i], b = people[j];
            if(a+b<=limit){
                j--;i++;ans++;
            }else{
                ans++;j--;
            }
        }
        return ans;
    }
};