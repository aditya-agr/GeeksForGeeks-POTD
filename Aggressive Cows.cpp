class Solution {
  public:
    bool check(vector<int> &a, int diff, int k){
        int prev=a[0], cnt=1;
        int n = a.size(), i = 1;
        while(i<n){
            if(a[i]-prev >= diff){
                cnt++;
                prev = a[i];
            }
            i++;
        }
        return cnt >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int l = 0;
        int h = stalls[n-1] - stalls[0];
        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(stalls, mid, k)){
                res = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return res;
    }
};