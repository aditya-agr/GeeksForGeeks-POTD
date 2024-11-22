class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int mn = prices[0], res = 0;
        int n = prices.size();
        for(int i=1; i<n; i++){
            if(prices[i] < mn)
                mn = prices[i];
            else
                res = max(res, prices[i]-mn);
        }
        return res;
    }
};