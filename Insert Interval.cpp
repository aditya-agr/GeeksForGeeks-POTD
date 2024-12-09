class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> res;
        int st = newInterval[0], ed = newInterval[1];
        bool merged = false;
        for(vector<int> x : intervals){
            if(x[1] < newInterval[0])
                res.push_back(x);
            else if(x[0] > newInterval[1]){
                if(!merged){
                    res.push_back({st, ed});
                    merged = true;
                }
                res.push_back(x);
            }
            else{
                st = min(st, x[0]);
                ed = max(ed, x[1]);
            }
        }
        if(!merged)
            res.push_back({st, ed});
        return res;
    }
};