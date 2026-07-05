class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n = s.length();
        vector<int> f(26, -1);
        int res = -1;
        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            if(f[idx] == -1)
                f[idx] = i;
            else
                res = max(res, i-f[idx]-1);
        }
        return res;
    }
};