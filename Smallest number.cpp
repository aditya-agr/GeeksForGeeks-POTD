
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string ans="";
        d--;
        while(d--){
            int res = min(9, s-1);
            s -= res;
            ans = char('0'+res) + ans;
        }
        if(s>9)
            return "-1";
        else 
            return char('0'+s) + ans;
    }
};