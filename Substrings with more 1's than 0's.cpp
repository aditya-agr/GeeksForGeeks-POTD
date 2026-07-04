class Solution {
  public:
    int countSubstring(string& s) {
        // Code Here
        int sum = 0, res = 0;
        int n = s.length();
        int smaller = 0;
        unordered_map<int, int> f;
        f[0] = 1;
        
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                smaller += f[sum];
                sum += 1;
            }
            else{
                sum -= 1;
                smaller -= f[sum];
            }
            res += smaller;
            f[sum]++;
        }
        return res;
    }
};