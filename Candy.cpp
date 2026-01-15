class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> candy(n, 1);
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1])
                candy[i] = max(candy[i], candy[i-1]+1);
        }
        for(int i=n-1; i>=0; i--){
            if(arr[i-1] > arr[i])
                candy[i-1] = max(candy[i-1], candy[i]+1);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res += candy[i];
        }
        return res;
    }
};
