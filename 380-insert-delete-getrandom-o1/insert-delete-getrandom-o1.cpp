class RandomizedSet {
public:
    //we can't use set/map bcs the random fn for a set doesnt necessarily take O(1) time in some cases
    unordered_map<int,int>m;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!m.count(val)){
            v.push_back(val);
            m[val] = v.size()-1;
        }else return false;
        return true;
    }
    
    bool remove(int val) {
        if(v.size()==0 || (!m.count(val))) return false;
        int x = m[val];
        int y = v[v.size()-1];
        v[x] = y;
        m[y] = x;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */