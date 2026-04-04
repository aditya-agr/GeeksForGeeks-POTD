class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        int tot = 1<<n;
        vector<string> ans;
        for(int i=0; i<tot; i++){
            int cur = i^(i>>1);
            string res = "";
            for(int j=n-1; j>=0; j--){
                if(cur&(1<<j))
                    res += '1';
                else
                    res += '0';
            }
            ans.push_back(res);
        }
        return ans;
    }
};