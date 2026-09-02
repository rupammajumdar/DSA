class Solution {
public:
    long long reverse(long long x) {
        long long reverseInt=0;
        long long a=x;
        while(a!=0){
            reverseInt=reverseInt*10+a%10;
            a=a/10;
        }
        if (reverseInt > INT_MAX || reverseInt < INT_MIN) {
            return 0;
        }

return reverseInt;
    }
};