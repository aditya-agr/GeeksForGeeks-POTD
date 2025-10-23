class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        vector<vector<int>> res;
        int n = points.size();
        vector<pair<int, int>> dp(n);
        for(int i=0; i<n; i++){
            dp[i].first = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dp[i].second = i;
        }
        sort(dp.begin(), dp.end());
        for(int i=0; i<k; i++){
            res.push_back(points[dp[i].second]);
        }
        return res;
        
    }
};