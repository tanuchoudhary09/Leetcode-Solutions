class StockSpanner {
public:
    stack<int>st;
    vector<int>v;
    StockSpanner() {

    }
    int next(int price) {
        v.push_back(price);
        int i=v.size()-1;
        while(st.size()>0 && v[st.top()]<=v[i]) st.pop();
        int ans;
        if(!st.size()) ans = i+1;
        else ans = i-st.top();
        st.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */