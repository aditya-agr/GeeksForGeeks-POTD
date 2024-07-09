class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res=INT_MIN, mn=INT_MAX;
        for(int x=0; x<n; x++){
            int i=x+1, j=n-1;
            while(i<j){
                int curr = arr[i]+arr[j]+arr[x];
                if(abs(curr-target)<=mn){
                    if(mn == abs(curr-target))
                        res = max(res, curr);
                    else
                        res = curr;
                    mn = abs(curr-target);
                }
                if(curr<target)
                    i++;
                else if(curr>target)
                    j--;
                else
                    return curr;
            }
        }
        return res;
    }
}