class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int cnt = 0;
        int n = s.size();
        int cur = 0;
        for(int i=0; i<n; i++){
            if(cur != (s[i]-'0'))
                cnt++;
            cur ^= 1;
        }
        int cnt2 = 0;
        cur = 1;
        for(int i=0; i<n; i++){
            if(cur != (s[i]-'0'))
                cnt2++;
            cur ^= 1;
        }
        return min(cnt, cnt2);
    }
};