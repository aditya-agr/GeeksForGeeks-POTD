class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int n = s.size(), num = 0;
        for(int i=0; i<n; i++)
            num = (num*10 + (s[i]-'0'))%13;
        return num%13 == 0;
    }
};