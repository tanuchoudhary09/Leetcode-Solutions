class Solution {
public:
    string intToRoman(int num) {
        string t = to_string(num);
        int n = t.length();
        vector<pair<int,string>>dict = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string ans = "";
        for(auto [key,sym] : dict){
            if(num==0) break;//not given in TCs but jic
            while(num>=key){
                ans += sym;
                num -= key;
            }
        }
        return ans;
    }
};