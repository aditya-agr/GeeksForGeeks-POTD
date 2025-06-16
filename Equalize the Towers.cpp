class Solution {
  public:
    int solve(int mid, vector<int>& heights, vector<int>& cost){
        int n = heights.size();
        int res = 0;
        for(int i=0; i<n; i++){
            res += abs(heights[i]-mid) * cost[i];
        }
        return res;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int l = *min_element(heights.begin(), heights.end());
        int h = *max_element(heights.begin(), heights.end());
        int res = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            int cost1 = solve(mid, heights, cost);
            int cost2 = solve(mid+1, heights, cost);
            if(cost1 < cost2){
                res = cost1;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};
