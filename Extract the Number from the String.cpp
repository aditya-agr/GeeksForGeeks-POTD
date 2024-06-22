class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        long long res=-1, curr=0, flag=1, n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                while (i<n && s[i]>='0' && s[i]<='9'){
                    curr = curr*10 + (s[i]-'0');
                    if(s[i]=='9')
                        flag=0;
                    i++;
                }
                if(flag) res = max(curr, res);
            }
            if(s[i]==' '){
                flag=1;
                curr=0;
            }
        }
        return res;
    }
};