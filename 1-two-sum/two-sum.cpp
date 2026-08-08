class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map < int , int > mp;
        vector<int> finalArr;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int complement = target - nums[i];
            if(mp.find(complement)!= mp.end()){
                finalArr.push_back(i);
                finalArr.push_back(mp[complement]);
            }
            mp[nums[i]]=i;
        }
        return finalArr;
    }
};