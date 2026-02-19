class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_set<int> st(arr.begin(), arr.end());
        int i=0;
        vector<int> res;
        for(int num=low; num<=high; num++){
            if(st.count(num))
                i++;
            else
                res.push_back(num);
        }
        return res;
    }
};