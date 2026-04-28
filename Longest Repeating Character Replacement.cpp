class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.length();
        int res = 0;
        for(int c=0; c<26; c++){
            int cur = 'A'+c;
            int cnt = 0;
            int i=0, j=0;
            while(j<n){
                if(s[j] != cur)
                    cnt++;
                while(cnt > k){
                    if(s[i] != cur)
                        cnt--;
                    i++;
                }
                res = max(res, j-i+1);
                j++;
            }
        }
        return res;
    }
};