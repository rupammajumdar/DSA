class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique;
        int n=digits.size();
        for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i!=j && i!=k && j!=k){
                    if(digits[k]%2==0 && digits[i]!=0){
                        int nums = digits[i]*100+digits[j]*10+digits[k];
                        unique.insert(nums);
                    }
                }
            }
           } 
        }
        return unique.size();
    }
};