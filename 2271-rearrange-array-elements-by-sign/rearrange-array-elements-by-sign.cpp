class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posArr;
        vector<int> negArr;
        vector<int> finalArr;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                posArr.push_back(nums[i]);
            }
            if(nums[i]<0){
                negArr.push_back(nums[i]);
            }
        }
        for(int i=0; i<posArr.size(); i++){
            finalArr.push_back(posArr[i]);
            finalArr.push_back(negArr[i]);
        }
        return finalArr;

    }
};