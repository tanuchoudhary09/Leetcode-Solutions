bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int n = boxTypes.size(),profit = 0;
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<=truckSize){
                profit+=boxTypes[i][0]*boxTypes[i][1];
                truckSize = truckSize-boxTypes[i][0];
            }else {
                profit += boxTypes[i][1]*truckSize;
                truckSize=0;
            }
            if(!truckSize) break;
        }
        return profit;
    }
};