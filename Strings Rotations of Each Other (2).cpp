class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        if(n != m)
            return false;
            
        string target = s1;
        string str = s2+s2;
        
        vector<int> lps(n, 0);
        int i=1, len=0;
        while(i<n){
            if(target[i] == target[len]){
                lps[i] = len+1;
                len++;
                i++;
            }
            else{
                if(len)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int j = 0;
        i = 0;
        while(j < 2*n){
            if(target[i] == str[j]){
                i++;
                j++;
                if(i == n)
                    return true;
            }
            else{
                if(i)
                    i = lps[i-1];
                else
                    j++;
            }
        }
        return false;
    }
};