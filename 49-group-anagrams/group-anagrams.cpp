class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>>ans;
        for(string s : strs){
            string og = s;
            sort(s.begin(),s.end());
            m[s].push_back(og);
        }
        for(auto v : m) ans.push_back(v.second);
        return ans;
    }
};