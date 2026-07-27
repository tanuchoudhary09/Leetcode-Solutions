class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int>m;
        int count = 0;
        for(int x:answers) m[x]++;
        for(auto x : m) {
            //int a = (x.second-x.first)/x.first + 1)*x.first;
            if(x.first+1<x.second && x.first) count+=((x.second+x.first)/(x.first+1))*(x.first+1);
            else if(x.first) count+=x.first+1;
            else count+=x.second;
        }
        return count;
    }
};