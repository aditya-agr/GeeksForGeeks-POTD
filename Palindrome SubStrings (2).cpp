class Solution {
  public:
    int solve(int left, int right, string &s){
        int len = 0;
        int n = s.length();
        while(left>=0 && right<n){
            if(s[left] == s[right])
                len += 2;
            else
                break;
            left--;
            right++;
        }
        return len/2;
    }
    int countPS(string &s) {
        // code here
        int n = s.length();
        int res = 0;
        for(int i=0; i<n; i++){
            res += solve(i, i+1, s);
            res += solve(i-1, i+1, s);
        }
        return res;
    }
};