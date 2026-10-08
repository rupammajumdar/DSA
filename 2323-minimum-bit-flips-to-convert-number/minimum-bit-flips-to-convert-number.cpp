class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorVal = start ^ goal;
        int count = 0;
        while (xorVal > 0) {
            count += (xorVal & 1);
            xorVal >>= 1;
        }
        return count;
    }
};