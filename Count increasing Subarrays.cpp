class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        int cnt = 1, res = 0;
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1])
                cnt++;
            else
                cnt = 1;
                
            if(cnt >= 2)
                res += cnt-1;
        }
        return res;
    }
};
