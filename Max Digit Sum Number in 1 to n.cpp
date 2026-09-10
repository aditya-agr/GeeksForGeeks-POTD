class Solution {
  public:
    int findMax(int n) {
        // code Here
        string s = to_string(n);
        int sz = s.length();
        
        int i = 1, pre = 0;
        while(i<sz){
            if(s[i] == '9')
                continue;
            if(pre){
                s[i] = '9';
            }
            else{
                s[i] = '9';
                s[i-1] -= 1;
                pre = 1;
            }
            i++;
        }
        int num1 = stoi(s);
        int sum1 = 0;
        for(int i=0; i<sz; i++)
            sum1 +=  s[i]-'0';
        
        int sum2 = 0, t = n;
        while(t){
            sum2 += t%10;
            t /= 10;
        }
        
        if(sum2 >= sum1)
            return n;
        
        return num1;
    }
};
