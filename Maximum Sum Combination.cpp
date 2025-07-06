class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int, int>> pq;
        int n = a.size();
        int m = b.size();
        for(int i=0; i<n; i++)
            pq.push({a[i]+b[m-1], m-1});
        
        vector<int> ans;
        while(!pq.empty() && k--){
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(sum);
            if(idx>0)
                pq.push({sum-b[idx]+b[idx-1], idx-1});
        }
        return ans;
    }
};