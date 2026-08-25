class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q; //to keep the track of the elements 
        q.push({startWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end()); // to search if the element we obtained by changing each word is there in the list or not
        st.erase(startWord);
        while(!q.empty()){
            string w = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(w== endWord) return steps;
            for(int i=0;i<w.size();i++){
                char og = w[i];
                for(char c = 'a';c<='z';c++){
                    w[i] = c;
                    if(st.count(w)){
                        st.erase(w);
                        q.push({w,steps+1});
                    }
                }
                w[i] = og;
            }
        }
        return 0;
    }
};