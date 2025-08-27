class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int sum = arr[i]+arr[j];
                int idx = lower_bound(arr.begin()+j+1, arr.end(), sum) - arr.begin();
                res += idx-j-1;
            }
        }
        return res;
        
    }
};
