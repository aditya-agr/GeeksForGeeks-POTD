class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int ans=0, high=n, low=0;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(mid*mid == n) 
                return mid;
            else if(mid*mid < n){
                low = mid+1;
                ans=mid;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};