class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        string res = "";
        for(char c : s){
            if((c>='a' && c<='z') || (c>='0' && c<='9'))
                res += c;
            if(c >= 'A' && c <= 'Z')
                res += (c-'A'+'a');
            
        }
        int n = res.length();
        for(int i=0; i<n; i++){
            if(res[i] != res[n-i-1])
                return false;
        }
        return true;
    }
};