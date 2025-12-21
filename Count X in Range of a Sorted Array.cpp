class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        int m = queries.size();
        vector<int> res;
        for(vector<int> &q : queries){
            int l = q[0];
            int r = q[1];
            int x = q[2];
            if(arr[l]>x || arr[r]<x)
                res.push_back(0);
            else{
                auto low = lower_bound(arr.begin()+l, arr.begin()+r+1, x);
                auto high = upper_bound(arr.begin()+l, arr.begin()+r+1, x);
                int freq = high - low;
                res.push_back(freq);
            }
        }
        return res;
    }
};