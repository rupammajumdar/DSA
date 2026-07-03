class Solution {
public:
    long findMaxConsecutiveOnes(vector<int>& nums) {
       int maxFreq = 0;
int freq = 0;

for(int i = 0; i < nums.size(); i++)
{
    if(nums[i] == 1)
    {
        freq++;
    }
    else
    {
        maxFreq = max(maxFreq, freq);
        freq = 0;
    }
}

maxFreq = max(maxFreq, freq);

return maxFreq;
}
};