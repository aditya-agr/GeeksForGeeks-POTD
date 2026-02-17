class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        vector<int> s(n), e(n);
        int i=0;
        for(vector<int> &a : arr){
            s[i] = a[0];
            e[i] = a[1];
            i++;
        }
        sort(e.begin(), e.end());
        sort(s.begin(), s.end());
        int cnt = 0, res = 0;
        int j=0, k=0;
        while(j<n && k<n){
            if(s[j] <= e[k])
                cnt++, j++;
            else
                cnt--, k++;
            res = max(cnt, res);
        }
        return res;
    }
};
