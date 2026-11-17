
class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int n = s.size();
        int i=0;
        while(i<n){
            int cnt = 0;
            while(s[i] == 'x'){
                cnt++;
                i++;
            }
            while(s[i] == 'y'){
                cnt--;
                i++;
            }
            if(cnt != 0)
                return false;
        }
        return true;
    }
};