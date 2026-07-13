class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;
        int lL = log10(low)+1;
        int lH = log10(high)+1;
        int m = lH-lL+1; //tell how many times the loop is gonna run
        while(m--){
            for(int j=0;j<=9-lL;j++){
                string t = s.substr(j,lL);
                int n = stoi(t);
                std::cout<<n<<endl;
                if(n>=low && n<=high) ans.push_back(n);
            }
            lL++;
        } 
        return ans;
    }
};