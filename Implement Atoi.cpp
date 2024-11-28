class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int n = strlen(s);
        int i = 0, neg = 0;
        long ans=0;
        while(s[i]==' ')
            i++;
        if(s[i] == '-'){
            neg = 1;
            i++;
        }
        
        while(s[i]>='0' && s[i]<='9'){
            int curr = (s[i]-'0');
            ans = ans*10 + curr;
            if(neg && -1*ans<INT_MIN)
                return INT_MIN;
            if(ans>INT_MAX)
                return INT_MAX;
            i++;
        }
        if(neg)
            ans = -1*ans;
        return ans;
    }
};