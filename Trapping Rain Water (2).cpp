class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> left(n), right(n);
        left[0] = 0;
        for(int i=1; i<n; i++){
            if(arr[left[i-1]] > arr[i])
                left[i] = left[i-1];
            else
                left[i] = i;
        }
        
        right[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            if(arr[right[i+1]] > arr[i])
                right[i] = right[i+1];
            else
                right[i] = i;
        }
        
        int res = 0;
        for(int i=1; i<n-1; i++)
            res += min(arr[left[i]], arr[right[i]]) - arr[i];
        
        return res;
        
    }
};