class Solution {
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // code here
        vector<vector<int>> box;
        int n = height.size();
        for(int i=0; i<n; i++){
            box.push_back({height[i], width[i], length[i]});
            box.push_back({width[i], height[i], length[i]});
            box.push_back({length[i], width[i], height[i]});
            box.push_back({width[i], length[i], height[i]});
            box.push_back({height[i], length[i], width[i]});
            box.push_back({length[i], height[i], width[i]});
        }
        sort(box.begin(), box.end());
        n = box.size();
        vector<int> dp(n+1);
        dp[0] = box[0][2];
        int res = dp[0];
        for(int i=1; i<n; i++){
            dp[i] = box[i][2];
            for(int j=0; j<i; j++){
                if(box[i][0] > box[j][0] && box[i][1] > box[j][1])
                    dp[i] = max(dp[j]+box[i][2], dp[i]);
            }
            res = max(res, dp[i]);
        }    
        return res;
    }
};