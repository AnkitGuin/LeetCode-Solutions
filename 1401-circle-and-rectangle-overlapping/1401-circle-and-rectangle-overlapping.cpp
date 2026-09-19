class Solution {
public:
    bool checkOverlap(int r, int cx, int cy,
        int x1, int y1, int x2, int y2) {
        int x = cx;
        int y = cy;
        if (cx < x1) x = x1;
        else if (cx > x2) x = x2;
        if (cy < y1) y = y1;
        else if (cy > y2) y = y2;
        int dx = cx - x;
        int dy = cy - y;
        return dx*dx + dy*dy <= r*r;
    }
};