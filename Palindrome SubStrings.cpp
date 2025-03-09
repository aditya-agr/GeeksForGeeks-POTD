class Solution {
  public:
    int length(int left, int right, string &s){
        int len = 0;
        int n = s.length();
        while(left>=0 && right<=n){
            if(s[left]==s[right])
                len += 2;
            else
                break;
            left--;
            right++;
        }
        return len;
    }
    int countPS(string &s) {
        // code here
        int cnt = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int len1 = length(i, i+1, s);
            cnt += len1/2;
            int len = length(i-1, i+1, s);
            cnt += len/2;
        }
        return cnt;
    }
};