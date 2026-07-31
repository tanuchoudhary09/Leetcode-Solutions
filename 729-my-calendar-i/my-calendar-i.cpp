class MyCalendar {
public:
    unordered_map<int,int>m;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        int a,b;
        for(auto x:m){
             a = x.first;
             b = x.second;
            if(startTime<b && endTime>a) return false;
        }
        m.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */