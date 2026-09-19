#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // 1. Find the nearest point on the rectangle to the circle's center
        // by clamping the center coordinates to the rectangle's bounds.
        int closestX = std::max(x1, std::min(xCenter, x2));
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        // 2. Calculate the distance from the circle's center to this closest point
        int distanceX = xCenter - closestX;
        int distanceY = yCenter - closestY;
        
        // 3. Check if the squared distance is less than or equal to the squared radius.
        // (Using squared values avoids the performance cost of a square root function)
        return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
    }
};