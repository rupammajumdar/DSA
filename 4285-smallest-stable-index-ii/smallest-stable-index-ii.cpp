class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int> smallest(n);
        smallest[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            smallest[i]= min(smallest[i+1],nums[i]);
        }
        int maxpref=INT_MIN;
        for(int i=0; i<n; i++){
            maxpref = max(maxpref, nums[i]);
            if(maxpref-smallest[i]<=k) return i;
        }
        return -1;


    }
};