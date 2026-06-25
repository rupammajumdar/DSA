class Solution {

public:
    void reverseArray(vector<int>& arr, int st, int end){
        while(st<end){
            swap(arr[st],arr[end]);
            st++;
            end--;
        }
        
    }
    vector<int> rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        k=k%n;
        if(n==0 || k==0) return nums;
    //    else if(n==2 && k<3) return reverseArray(nums,0,1);
    //    else{
       reverseArray(nums, 0, n-1);
       reverseArray(nums,0, k-1);
       reverseArray(nums,k,n-1);
        return nums;
    }
     
};