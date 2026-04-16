class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int n = s.size();
        int i=0;
        while(s[i]==' ' || s[i]=='+') i++;
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        while(s[i]==' ') i++;
        long long res = 0;
        while(s[i]>='0' && s[i]<='9'){
            int num = s[i]-'0';
            res = res*10 + num;
            if(!neg && res>INT_MAX)
                return INT_MAX;
            if(neg && res*-1<INT_MIN)
                return INT_MIN;
            i++;
        }
        return (neg) ? -1*res : res;
    }
};
