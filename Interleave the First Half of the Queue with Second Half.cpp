class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        vector<int> res(n);
        int i=0, j=n/2;
        for(int x=0; x<n; x+=2){
            res[x] = q.front();
            q.pop();
        }
        for(int x=1; x<n; x+=2){
            res[x] = q.front();
            q.pop();
        }
        for(int x=0; x<n; x++){
            q.push(res[x]);
        }
    }
};