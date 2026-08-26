class Solution {
    unordered_map<string,int>mp;
    vector<vector<string>>ans;
    string start;
public: 
    void dfs(string w, vector<string> &seq){
        if(w == start) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mp[w];
        int n = w.size();
        for(int i=0;i<n;i++){
            char og = w[i];
            for(char c = 'a';c<='z';c++){
                w[i] = c;
                if(mp.find(w)!=mp.end() && mp[w]+1 == steps){
                    seq.push_back(w);
                    dfs(w,seq);
                    seq.pop_back();
                }
            }
            w[i] = og;
        }
    }
    vector<vector<string>> findLadders(string startWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(startWord);
        unordered_set<string>st(wordList.begin(),wordList.end()); 
        //vector<string> alr_used;
        //alr_used.push_back(startWord);
        //int level = 0;
        mp[startWord] = 1;
        start = startWord;
        int n = startWord.size();
        //vector<vector<string>>ans;
        st.erase(startWord);
        while(!q.empty()){
            string w = q.front();
            int steps = mp[w];
            q.pop();
            
            //  if(steps>level){
            //     level = steps;
            //    for(auto x : alr_used) st.erase(x); //??
            //     alr_used.clear();
            //  }
             if(w==endWord) break;
            //string w = v.back();
            // if(w==endWord){
            //     if(ans.size()==0) ans.push_back(v);
            //     else if(ans[0].size()==v.size()) ans.push_back(v); //??
            //     continue;
            // }
            for(int i=0;i<n;i++){
                char og = w[i];
                for(char c = 'a';c<='z';c++){
                    w[i] = c;
                    if(st.count(w)){
                        st.erase(w);
                        q.push(w);
                        mp[w] = steps+1;
                        //v.push_back(w);
                        // v.pop_back();
                        //alr_used.push_back(w);
                    }
                }
                w[i] = og;
            }
            
        }
        if(mp.find(endWord)!=mp.end()) {
                vector<string> seq;
                seq.push_back(endWord);
                dfs(endWord,seq);
            }
        return ans;
    }
};