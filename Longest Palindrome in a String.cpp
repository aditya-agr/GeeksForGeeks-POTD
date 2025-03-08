class Solution {
  public:
    int solve(int left, int right, string &s){
        int n = s.length();
        int len = 0;
        while(left>=0 && right<n){
            if(s[left] == s[right])
                len += 2;
            else
                break;
            left--;
            right++;
        }
        return len;
    }
    string longestPalindrome(string &s) {
        // code here
        int maxlen = 0, start = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int len = 1 + solve(i-1, i+1, s);
            if(len > maxlen){
                maxlen = len;
                start = i - len/2;
            }
        }
        for(int i=1; i<n; i++){
            int len = solve(i-1, i, s);
            if(len > maxlen){
                maxlen = len;
                start = i - len/2;
            }
        }
        string res = s.substr(start, maxlen);
        return res;
    }
};