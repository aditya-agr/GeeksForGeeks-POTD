class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int ans=0, cnt=0;
        int n=arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1])
                cnt++;
            else
                cnt=0;
            ans = max(cnt, ans);
        }
        return ans;
    }
    
};