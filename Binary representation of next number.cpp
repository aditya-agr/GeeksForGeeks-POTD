class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int j=0;
        while(s[j]=='0')
            j++;
        string r = s.substr(j);
        
        int n = r.length();
        int i=n-1;
        while(i>=0 && r[i]=='1'){
            r[i] = '0';
            i--;
        }
        if(i<0)
            r = '1'+r;
        else
            r[i] = '1';
        
        return r;
    }
};