class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double sum = 0;
        for(int x : arr){
            sum += x;
            pq.push(x);
        }
        double curr = 0;
        int cnt = 0;
        while(curr < sum/2){
            double rem = pq.top()/2;
            pq.pop();
            curr += rem;
            pq.push(rem);
            cnt++;
        }
        return cnt;
    }
};