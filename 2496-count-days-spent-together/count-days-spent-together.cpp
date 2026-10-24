#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calc_days(int day, int month, int dayd, int daym) {
        vector<int> v = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == daym) return dayd - day + 1;
        int mon = 0;
        for (int i = month + 1; i < daym; i++) mon += v[i];
        return (v[month] - day + 1) + mon + dayd;
    }

    int countDaysTogether(string a, string b, string c, string d) {
        int aAm = (a[0] - '0') * 10 + (a[1] - '0');
        int aAd = (a[3] - '0') * 10 + (a[4] - '0');
        int lAm = (b[0] - '0') * 10 + (b[1] - '0');
        int lAd = (b[3] - '0') * 10 + (b[4] - '0');
        int aBm = (c[0] - '0') * 10 + (c[1] - '0');
        int aBd = (c[3] - '0') * 10 + (c[4] - '0');
        int lBm = (d[0] - '0') * 10 + (d[1] - '0');
        int lBd = (d[3] - '0') * 10 + (d[4] - '0');
        int startM, startD;
        if (aAm > aBm || (aAm == aBm && aAd > aBd)) {
            startM = aAm;
            startD = aAd;
        } else {
            startM = aBm;
            startD = aBd;
        }
        int endM, endD;
        if (lAm < lBm || (lAm == lBm && lAd < lBd)) {
            endM = lAm;
            endD = lAd;
        } else {
            endM = lBm;
            endD = lBd;
        }
        if (startM > endM || (startM == endM && startD > endD)) {
            return 0;
        }
        return calc_days(startD, startM, endD, endM);
    }
};