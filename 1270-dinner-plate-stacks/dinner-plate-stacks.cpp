class DinnerPlates {
public:
    int capacity;
    int i;
    unordered_map<int,vector<int>>m;
    priority_queue<int,vector<int>,greater<int>>pq;
    DinnerPlates(int capacity) {
        this->capacity=capacity;
        i=-1;
    }
    
    void push(int val) {
        int idx;
        while(!pq.empty()){
            idx = pq.top();
            if(idx<=i && m[idx].size()>=capacity ) pq.pop();
            else break;
        }
         idx = pq.empty()?i+1:pq.top();
        m[idx].push_back(val);
        i=max(i,idx);
        if(m[idx].size()<capacity) pq.push(idx);
        else if(!pq.empty() && pq.top()==idx) pq.top();
    }
    
    int pop() {
        while(i>-1 && (!m.count(i) || m[i].empty())){
            m.erase(i);i--;
        }
        if(i<0) return -1;
        return popAtStack(i);
    }
    
    int popAtStack(int index) {
        if(!m.count(index) || m[index].empty()) return -1;
        vector<int>&v = m[index];
        int x = v.back();
        v.pop_back();
        pq.push(index);
        if(index==i){
            while(i>-1 && (!m.count(i) || m[i].empty())){
                m.erase(i);i--;
            }
        }
        return x;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */