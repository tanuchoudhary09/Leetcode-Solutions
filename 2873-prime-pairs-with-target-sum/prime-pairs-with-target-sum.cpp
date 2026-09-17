class Solution {
    void fillsieve(vector<bool>& sieve){
        int n=sieve.size()-1;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*2;j<=n;j=j+i){
                sieve[j]=false;
            }
        }
    }
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n<=3) return {};
        //unordered_set<int>s;
        vector<vector<int>>ans;
        
        vector<bool>isPrime(n+1,true);
        fillsieve(isPrime);
        for(int i=2;i<=n/2;i++){
            if(isPrime[i] && isPrime[n-i]) ans.push_back({i,n-i});;
        }
        return ans;
    }
};