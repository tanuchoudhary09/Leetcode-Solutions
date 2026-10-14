class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()) return false;
        vector<int> fq(26,0);
        for(char c : magazine) fq[c - 'a']++;
        for(char c : ransomNote) fq[c - 'a']--;
        for(int i = 0; i < 26; i++){
            if(fq[i] < 0) return false;
        }
        return true;
    }
};