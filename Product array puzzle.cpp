class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // code here
        long long int prod=1, index=-1;
        int n = nums.size();
        vector<long long int> res(n);
        for(int i=0; i<n; i++){
            if(nums[i]!=0)
                prod *= nums[i];
            else{
                if(index!=-1) return res;
                index = i;
            }
        }
        if(index != -1){
            res[index] = prod;
            return res;
        }
        for(int i=0; i<n; i++)
            res[i] = prod/nums[i];
        return res;
    }
};