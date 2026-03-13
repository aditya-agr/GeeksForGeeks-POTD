class Solution {
  public:
    vector<string> res;
    void solve(string &s, string cur, int idx, int dot){
        if(dot > 4)
            return;
        int n = s.length();
        if(idx == n){
            if(dot == 4){
                cur.pop_back();
                res.push_back(cur);
                return;
            }
        }
        for(int i=idx; i<n; i++){
            string tmp = s.substr(idx, i-idx+1);
            int num = stoi(tmp);
            if(num > 255 || (tmp.length()>1 && tmp[0]=='0'))
                break;
            solve(s, cur+tmp+".", i+1, dot+1);
        }
    }
    vector<string> generateIp(string &s) {
        // code here
        string cur="";
        solve(s, cur, 0, 0);
        return res;
    }
};