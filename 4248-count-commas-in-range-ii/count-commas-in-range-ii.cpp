class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long totalcommas=0;
        long long base=1000;
        while(n>=base){
            totalcommas= totalcommas+ (n-base+1);
            base=base*1000;
        }
        return totalcommas;
    }
};