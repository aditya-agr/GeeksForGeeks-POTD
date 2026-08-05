class Solution {
  public:
    int solve(vector<int> &arr, int x){
        int count = 0;
        int sum = 0;
        int n = arr.size();
        int j = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            while(sum > x)
                sum -= arr[j++];
            count += (i-j+1);
        }
        return count;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return solve(arr, r) - solve(arr, l-1);
    }
};