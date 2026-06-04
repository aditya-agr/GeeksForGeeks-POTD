class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int cnt = 0, res = 0;
        for(char c : s){
            if(c == '1')
                cnt--;
            else
                cnt++;
            
            if(cnt < 0) 
                cnt = 0;
            
            res = max(res, cnt);
        }
        return res == 0 ? -1 : res;
    }
};