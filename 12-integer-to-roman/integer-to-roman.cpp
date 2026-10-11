class Solution {
public:
    string intToRoman(int num) {
        vector<string> th = {"","M","MM","MMM","MMMM"};
        vector<string> hun = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string ans = th[num/1000] + hun[(num/100) % 10] + tens[(num/10) % 10] + ones[num % 10];
        return ans;
    }
};