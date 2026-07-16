class NumArray {
public:
    vector<int>v;
    NumArray(vector<int>& nums) {
        v = nums;int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            v[i] =(int)sum;
        }
    }
    int sumRange(int left, int right) {
        if(!left) return v[right];
        else return v[right] - v[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */