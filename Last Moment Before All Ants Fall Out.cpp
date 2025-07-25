
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int res = 0;
        for(int x : left)
            res = max(res, x);
            
        for(int x : right)
            res = max(res, n-x);
            
        return res;
    }
};