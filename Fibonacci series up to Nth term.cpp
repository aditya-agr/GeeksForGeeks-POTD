class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        int m = 1e9+7;
        vector<int> res(n+1,0);
        res[1]=1;
        for(int i=2; i<=n; i++)
            res[i]=(res[i-1]%m+res[i-2]%m)%m;
        return res;
    }
};