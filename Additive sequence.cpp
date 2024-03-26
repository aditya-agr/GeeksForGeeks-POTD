class Solution {
  public:
    string add(string f, string s){
        reverse(f.begin(), f.end());
        reverse(s.begin(), s.end());
        int carry=0, val;
        int n=f.size(), m=s.size();
        int i=0, j=0;
        string ans="";
        while(i<n && j<m){
            val = (f[i++]-'0')+(s[j++]-'0')+carry;
            carry = val/10;
            ans += (val%10+'0');
        }
        while(j<m){
            val = (s[j++]-'0')+carry;
            carry = val/10;
            ans += (val%10+'0');
        }
        while(i<n){
            val = (f[i++]-'0')+carry;
            carry = val/10;
            ans += (val%10+'0');
        }
        while(carry){
            val = carry;
            carry = val/10;
            ans += (val%10+'0');
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool help(string a,string b,string c){
        string sum = add(a,b);
        int i=0,j=0;
        while(i<c.length() and j<sum.length()){
            if(c[i]!=sum[j])return false;
            i++;
            j++;
        }
        if(j!=sum.length())return false;
        if(i==c.length())return true;
        c=c.substr(i);
        return help(b,sum,c);
    }
    bool isAdditiveSequence(string s) {
        // Your code here
        int n=s.size();
        for(int i=0; i<n/2; i++){
            for(int j=i+1; j<n-1; j++){
                string first = s.substr(0, i+1);
                string second = s.substr(i+1, j-i);
                string last = s.substr(j+1);
                if(help(first, second, last))
                    return true;
            }
        }
        return false;
    }
};