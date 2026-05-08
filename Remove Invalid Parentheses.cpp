class Solution {
  public:
    void dfs(string &s, int idx, int open, int ro, int rc, string curr, set<string> &st){
        if(idx == s.length()){
            if(open==0 && ro==0 && rc==0)
                st.insert(curr);
            return;
        }
        if(s[idx] == '('){
            if(ro > 0)
                dfs(s, idx+1, open, ro-1, rc, curr, st);
            dfs(s, idx+1, open+1, ro, rc, curr+s[idx], st);
        }
        else if(s[idx] == ')'){
            if(rc > 0)
                dfs(s, idx+1, open, ro, rc-1, curr, st);
            if(open > 0)
                dfs(s, idx+1, open-1, ro, rc, curr+s[idx], st);
        }
        else
            dfs(s, idx+1, open, ro, rc, curr+s[idx], st);
        
    }
    vector<string> validParenthesis(string &s) {
        // code here
        int n = s.length();
        int open=0, close=0;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                open++;
            else if(s[i] == ')'){
                if(open > 0)
                    open--;
                else
                    close++;
            }
        }
        set<string> st;
        dfs(s, 0, 0, open, close, "", st);
        vector<string> res(st.begin(), st.end());
        return res;
    }
};
