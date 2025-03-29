
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> idx(n);
        for(int i=0; i<n; i++)
            idx[i] = {deadline[i], profit[i]};
        
        sort(idx.begin(), idx.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int cnt = 0, profits = 0;
        for(int i=0; i<n; i++){
            if(idx[i].first > cnt){
                cnt++;
                profits += idx[i].second;
                pq.push(idx[i].second);
            }
            else if(idx[i].second > pq.top()){
                profits -= pq.top();
                pq.pop();
                profits += idx[i].second;
                pq.push(idx[i].second);
            }
        }
        return {cnt, profits};
    }
};
