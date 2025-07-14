class Solution {
  public:
    unordered_set<int> st;
    vector<int> dp;
    int solve(int i, string &s){
        int n = s.length();
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int res = n+1, num = 0;
        for(int j=i; j<n; j++){
            num = num*2 + (s[j]=='1');
            if(s[i]!='0' && st.count(num))
                res = min(res, 1+solve(j+1, s));
        }
        return dp[i] = res;
            
    }
    int cuts(string s) {
        // code here
        if(s[0] == '0')
            return -1;
        for(int i=1; i<1e9; i*=5)
            st.insert(i);
        int n = s.length();
        dp.resize(n, -1);
        int res = solve(0, s);
        return (res>n) ? -1 : res;
    }
};