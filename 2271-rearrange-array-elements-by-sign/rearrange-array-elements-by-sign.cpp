class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> finalArr(nums.size());
        int posIndex=0;
        int negIndex=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                finalArr[posIndex]=nums[i];
                posIndex+=2;
            }
            if(nums[i]<0){
                finalArr[negIndex]=nums[i];
                negIndex+=2;
            }
        }
       
        return finalArr;

    }
};