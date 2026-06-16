class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> res(1);
        int xr=0, cur=0;
        for(vector<int> &q : queries){
            if(q[0] == 0)
                res.push_back(q[1]^cur);
            else{
                xr ^= q[1];
                cur ^= q[1];
            }
        }
        int n = res.size();
        for(int i=0; i<n; i++)
            res[i] ^= xr;
        sort(res.begin(), res.end());
        return res;
    }
};
