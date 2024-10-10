class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> res(n, -1);
        for(int x : arr)
            if(x != -1)
                res[x] = x;
        return res;
    }
};