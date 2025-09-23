class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        int n = q.size();
        vector<int> t(n);
        for(int i=0; i<n; i++){
            t[i] = q.front();
            q.pop();
        }
        for(int i=n-1; i>=0; i--)
            q.push(t[i]);
    }
};