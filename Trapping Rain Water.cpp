class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l=0, r=n-1;
        int left=0, right=0;
        int ans=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(arr[l]>=left)
                    left = arr[l];
                else
                    ans += left - arr[l];
                l++;
            }
            else{
                if(arr[r]>=right)
                    right = arr[r];
                else
                    ans += right - arr[r];
                    r--;
            }
        }
        return ans;
    }
};