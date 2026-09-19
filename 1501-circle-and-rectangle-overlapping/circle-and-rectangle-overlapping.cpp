class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int newxC1 = x1-xCenter;
        int newyC1 = y1-yCenter;
        int newxC2 = x2-xCenter;
        int newyC2 = y2-yCenter;
        int l1 = 0;
        if(newxC1>0) l1 = newxC1;
        else if(newxC2<0) l1 = newxC2;
        int l2 = 0;
        if(newyC1>0) l2 = newyC1;
        else if(newyC2<0) l2 = newyC2;
        return l1*l1 + l2*l2 <=radius*radius;
    }
};