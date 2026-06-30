class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        unordered_set<int> st(b.begin(), b.end());
        vector<int> vec;
        for(int i=0; i<n; i++){
            if(i>0 && a[i]==a[i-1])
                continue;
            if(st.count(a[i]))
                vec.push_back(a[i]);
        }
        vector<int> res;
        for(int x : vec){
            if(res.empty() || x>res.back())
                res.push_back(x);
            else{
                int idx = lower_bound(res.begin(), res.end(), x) - res.begin();
                res[idx] = x;
            }
        }
        int sz = res.size();
        int ans = n - sz;
        ans += m-sz;
        return ans;
        
    }
};