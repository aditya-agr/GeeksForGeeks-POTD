class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.length();
        int sum = 0;
        for(int i=0; i<n; i++){
            int cur = 0;
            for(int j=i; j<n; j++){
                cur = cur*10 + (s[j]-'0');
                sum += cur;
            }
        }
        return sum;
    }
};