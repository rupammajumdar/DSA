class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxprofit=0;
        if(nums.size()==1) return 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]){
                maxprofit+=(nums[i+1]-nums[i]);
            }
        }
        return maxprofit;
    }
};