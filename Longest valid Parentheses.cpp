class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int res=0;
        int co=0, cc=0;
        int n = str.length();
        for(int i=0; i<n; i++){
            if(str[i]=='(')
                co++;
            else 
                cc++;
            if(cc==co)
                res = max(res, cc+co);
            if(cc>co)
                cc = co = 0;
        }
        cc = co = 0;
        for(int i=n-1; i>=0; i--){
            if(str[i]=='(')
                co++;
            else 
                cc++;
            if(cc==co)
                res = max(res, cc+co);
            if(cc<co)
                cc = co = 0;
        }
        return res;
    }
};