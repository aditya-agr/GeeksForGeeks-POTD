class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        int n = arr.size();
        vector<int> a(n);
        for(int i=0; i<n; i++){
            string st = arr[i];
            int h = (st[0]-'0')*10 + (st[1]-'0');
            int m = (st[3]-'0')*10 + (st[4]-'0');
            int s = (st[6]-'0')*10 + (st[7]-'0');
            a[i] = h*60*60 + m*60 + s;
        }
        sort(a.begin(), a.end());
        int res = 24*60*60-a[n-1] + a[0];
        for(int i=1; i<n; i++){
            res = min(res, a[i]-a[i-1]);
        }
        return res;
    }
};
