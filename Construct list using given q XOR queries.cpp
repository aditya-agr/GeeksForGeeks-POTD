class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> res;
        int axor=0;
        for(int i=q-1; i>=0; i--){
            if(queries[i][0]==0)
                res.push_back(queries[i][1]^axor);
            else
                axor ^= queries[i][1];
        }
        res.push_back(axor);
        sort(res.begin(), res.end());
        return res;
    }
};