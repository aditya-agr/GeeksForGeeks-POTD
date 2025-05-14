class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if(n == 1)
            return "1";
        string s = countAndSay(n-1);
        string res = "";
        int cnt = 1;
        char c = s[0];
        int m = s.length();
        for(int i=1; i<m; i++){
            if(s[i] == c)
                cnt++;
            else{
                res += to_string(cnt) + c;
                cnt = 1;
                c = s[i];
            }
        }
        res += to_string(cnt) + c;
        return res;
    }
};