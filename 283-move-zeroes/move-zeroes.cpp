class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
              int j=-1;
        for(int p=0; p<nums.size(); p++){
            if(nums[p]==0){
                j=p;
                break;
            }
        }
        if(j==-1) return nums;
        for(int i=j+1;i<nums.size(); i++){
            if(nums[i]!=0){
            swap(nums[j],nums[i]);
            j++;
            }
        }
        return nums;
    }
   
 
};