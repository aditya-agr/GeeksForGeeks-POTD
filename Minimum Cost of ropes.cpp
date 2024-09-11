class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long it : arr)
            pq.push(it);
        long long res=0;
        while(pq.size()!=1){
            long long a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            res += a+b;
            pq.push(a+b);
        }
        return res;
    }
};
