class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<int> pq(arr.begin(), arr.end());
        int res = 0, mod = 1e9+7;
        while(k && !pq.empty()){
            int n = pq.top();
            pq.pop();
            res = (res+n)%mod;
            k--;
            if(n-1 > 0)
                pq.push(n-1);
        }
        return res;
    }
};