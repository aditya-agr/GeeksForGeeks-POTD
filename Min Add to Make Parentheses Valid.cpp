class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char> st;
        int cnt = 0, res = 0;
        for(char c : s){
            if(c == '('){
                cnt++;
            }
            else{
                if(cnt == 0){
                    res++;
                    continue;
                }
                cnt--;
            }
        }
        return res + cnt;
    }
};