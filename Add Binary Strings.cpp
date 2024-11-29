class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int n = s1.length();
        int m = s2.length();
        int i=0, j=0;
        int carry=0;
        string res = "";
        while(i<n && j<m){
            int curr = (s1[i++]-'0');
            curr += (s2[j++]-'0');
            curr += carry;
            res += (curr%2==1) ? '1' : '0';
            carry = (curr>1) ? 1 : 0;
        }
        while(i<n){
            int curr = (s1[i++]-'0') + carry;
            res += (curr%2==1) ? '1' : '0';
            carry = (curr>1) ? 1 : 0;
        }
        while(j<m){
            int curr = (s2[j++]-'0') + carry;
            res += (curr%2==1) ? '1' : '0';
            carry = (curr>1) ? 1 : 0;
        }
        if(carry)
            res += '1';
        reverse(res.begin(), res.end());
        int x = 0;
        while(res[x]=='0')
            x++;
        res = res.substr(x);
        return res;
    }
};