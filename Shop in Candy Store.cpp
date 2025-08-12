class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin() , prices.end());
        
        int len = prices.size();
        int n = len;
        
        int minSum = 0 , maxSum = 0;
        
        int i = 0;
        while(i < len)
        {
            minSum = minSum + prices[i];
            maxSum = maxSum + prices[n-i-1];
            i++;
            len = len - k;
        }
        
        return {minSum , maxSum};
    }
};