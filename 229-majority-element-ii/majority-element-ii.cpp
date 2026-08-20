class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        // if((n/3) < 1){
        //     return nums;
        // }
        // else{
            map<int,int> freq;
            for(int i=0; i<n; i++){
                freq[nums[i]]++;
            }
            for(auto &it : freq){
                if(it.second>n/3) {

                   result.push_back(it.first);
                    }
            }
            return result;
        // }
    }
};