#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
       vector<int> freq(10,0);
       for(int digit : digits){
        freq[digit]++;
       }
       int validnum=0;
       for(int num=100; num<=998; num+=2){
        int hundreds =num/100;
        int tens= (num/10)%10;
        int unit = num%10;
        freq[hundreds]--;
        freq[tens]--;
        freq[unit]--;
        if(freq[hundreds]>=0 && freq[tens]>=0&&freq[unit]>=0) validnum++;
         freq[hundreds]++;
        freq[tens]++;
        freq[unit]++;
        


       
       }
       return validnum;

}
};