class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());

        long long cost = 0;

        while (pq.size() > 1) {

            int a = pq.top(); pq.pop();

            int b = pq.top(); pq.pop();

            cost += a + b;

            pq.push(a + b);

        }

        return (int)cost;
    }
};
