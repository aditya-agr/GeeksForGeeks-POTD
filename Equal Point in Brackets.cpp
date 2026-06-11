class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int cntc = 0;
        int n = s.length();
        for(int i=0; i<n; i++)
            if(s[i] == ')')
                cntc++;
        
        int cnto = 0;
        for(int i=0; i<n; i++){
            if(cnto == cntc)
                return i;
            if(s[i] == ')')
                cntc--;
            else
                cnto++;
        }
        return n;
    }
};