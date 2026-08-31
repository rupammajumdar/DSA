class Solution {
public:
    bool isPalindrome(int x) {
        long long revNum=0;
        long long actualnum=x;
    while(actualnum>0){
    revNum=(revNum*10)+(actualnum%10);
    actualnum=actualnum/10;
    }
    if(revNum!=x) return false;
    return true;
    
    }
};