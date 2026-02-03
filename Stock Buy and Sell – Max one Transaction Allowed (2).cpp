
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int res = 0, mn = INT_MAX;
        for(int i=0; i<n; i++){
            if(prices[i] < mn)
                mn = prices[i];
            res = max(res, prices[i]-mn);
        }
        return res;
    }
};
