class Solution {
  public:
    long long solve(vector<int>& heights, vector<int>& cost, int h){
        long long tot = 0;
        int n = heights.size();
        for(int i=0; i<n; i++){
            tot += abs(h-heights[i])*cost[i];
        }
        return tot;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int l = *min_element(heights.begin(), heights.end());
        int h = *max_element(heights.begin(), heights.end());
        long long res = 0;
        while(l<=h){
            int mid = l+(h-l)/2;
            long long prev = solve(heights, cost, mid-1);
            long long cur = solve(heights, cost, mid);
            long long nxt = solve(heights, cost, mid+1);
            if(cur<=nxt){
                res = cur;
                h =  mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};