class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        int n = intervals.size();
        for(int i=0; i<n; i++){
            if(intervals[i][0] >= newInterval[0]){
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
        }
        if(intervals.size() == n)
            intervals.push_back(newInterval);
            
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=0; i<=n; i++){
            if(res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};