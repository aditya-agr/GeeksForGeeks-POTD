class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res(n);
        sort(arr.begin(), arr.end());
        int i=0, j=n-1;
        int x=0;   
        while(i<=j){
            res[x++] = arr[i++];
            if(i<=j)
                res[x++] = arr[j--];
        }
        long long ans = abs(res[n-1]-res[0]);
        for(int i=1; i<n; i++)
            ans += abs(res[i] - res[i-1]);
        return ans;
    }
};