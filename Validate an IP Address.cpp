
class Solution {
  public:
    int isValid(string str) {
        // code here
        string num="";
        int cnt=0;
        int n = str.size();
        for(int i=0; i<n; i++){
            if(str[i!='.'){
                if(num.empty() && str[i]=='0')
                    return false;
                num += str[i];
            }
            else{
                if(num.empty())
                    return false;
                int n = stoi(num);
                if(n<0 || n>255)
                    return false;
                num = "";
                cnt++;
            }
        }
        int n=-1;
        if(!num.empty())
            n = stoi(num);
        if(n<0 || n>255)
            return false;
        cnt++;
        return cnt==4;
    }
};