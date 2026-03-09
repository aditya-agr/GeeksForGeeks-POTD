class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.length();
        vector<int> idx(10, -1);
        for(int i=0; i<n; i++){
            idx[s[i]-'0'] = i;
        }
        for(int i=0; i<n; i++){
            int t = s[i]-'0';
            for(int j=9; j>t; j--){
                if(idx[j] > i){
                    swap(s[i], s[idx[j]]);
                    return s;;
                }
            }
        }
        return s;
    }
};