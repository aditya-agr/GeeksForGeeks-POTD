class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int n = a.size();
        int i=0, j=0, k=0;
        int mindif=INT_MAX;
        vector<int> res;
        while(i<n && j<n && k<n){
            int mn = min(a[i], min(b[j], c[k]));
            int mx = max(a[i], max(b[j], c[k]));
            if(mx-mn < mindif){
                mindif = mx-mn;
                res = {a[i], b[j], c[k]};
            }
            if(a[i]<=b[j] && a[i]<=c[k])
                i++;
            else if(b[j]<=a[i] && b[j]<=c[k])
                j++;
            else
                k++;
        }
        sort(res.rbegin(), res.rend());
        return res;
    }
};