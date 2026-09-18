class Solution {
        priority_queue<int> mx;
        priority_queue<int,vector<int>,greater<int>> mn;
        unordered_map<int,int>check;//it will store the elements of the prv window after the window slides and check id they are on the top of the heaps
        int mxS = 0, mnS = 0;
        void prune_mx(){
            //prunes if there are any older elements present in the heaps
            while(!mx.empty()){
                int val = mx.top();
                if(check.find(val)!= check.end() && check[val]>0){
                    check[val]--;
                    if(check[val]==0) check.erase(val);
                    mx.pop();
                }else break;
            }
        }
        void prune_mn(){
            while(!mn.empty()){
                int val = mn.top();
                if(check.find(val)!= check.end() && check[val]>0){
                    check[val]--;
                    if(check[val]==0) check.erase(val);
                    mn.pop();
                }else break;
            }
        }
        void balance(){
            // checks the balance
            if(mxS> mnS+1){
                mn.push(mx.top());
                mx.pop();
                mxS--;
                mnS++;
                prune_mx();
            } else if(mxS< mnS){
                mx.push(mn.top());
                mn.pop();
                mnS--;
                mxS++;
                prune_mn();
            }
        }
        void add(int num){
            // we push the elements and then check for the balance
            if(mx.empty() || num<=mx.top()){
                mx.push(num);
                mxS++;
            }else{
                mn.push(num);
                mnS++;
            }
            balance();
        }
        void remove(int num){
            check[num]++;
            if(num<=mx.top()){
                mxS--;
                if(num==mx.top()) prune_mx();
            }else{
                mnS--;
                if(!mn.empty() && num == mn.top()) prune_mn();
            }
            balance();
        }
        double get_median(int k){
            if(k%2!=0) return (double)mx.top();
            else return ((double)mx.top() + (double)mn.top())/2.0;
        }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double>ans;
        for(int i=0;i<k;i++) add(nums[i]);
        ans.push_back(get_median(k));
        for(int i=k;i<n;i++){
            add(nums[i]);
            remove(nums[i-k]);
            ans.push_back(get_median(k));
        }
        return ans;
    }
};