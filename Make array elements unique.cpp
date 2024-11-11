class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i]<=arr[i-1]){
                int inc = (arr[i-1]-arr[i]+1);
                arr[i]+=inc;
                cnt+=inc;
            }               
        }
        return cnt;
    }
};