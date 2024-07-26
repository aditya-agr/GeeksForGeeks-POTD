class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> idx(26);
        int cnt=0, len=0;
        for(char i : str){
            if(i!=' '){
                if(!idx[i-'a']){
                    idx[i-'a'] = 1;
                    cnt++;
                }
                len++;
            }
        }
        return (len>25 && (26-cnt)<=k);
    }
};