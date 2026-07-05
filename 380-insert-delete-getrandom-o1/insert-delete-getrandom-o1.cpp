class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>m;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            v.push_back(val);
            m[val] = v.size()-1;
        }else return false;
        return true;
    }
    
    bool remove(int val) {
        if(v.size()==0) return false;
        if(m.find(val)==m.end()) return false;
        int n =m[val];
        m[v[v.size()-1]] = n;
        v[n]=v[v.size()-1];
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
       return v[rand() % v.size()]; //random fn
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */