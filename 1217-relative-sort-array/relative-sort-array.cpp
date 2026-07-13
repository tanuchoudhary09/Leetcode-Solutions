class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<int>v(1001,0);
        int j=0;
        for(int num:arr1) v[num]++;
        for(int num:arr2) {
            while(v[num]--){
                arr1[j] = num;
                j++;
            }
            v[num]=0;
        }
        std::cout<<j<<endl;
        for(int i=0;i<=1000;i++){
            while(v[i]--) {
                arr1[j] = i;
                j++;
            }
        }
        return arr1;
    }
};