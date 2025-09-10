
class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.length();
        vector<int> v(10, -1);
        for(int i=0; i<n; i++)
            v[s[i]-'0'] = i;
        
        for(int i=0; i<n; i++){
            for(int j=9; j>=1; j--){
                if(v[j]!=-1 && v[j]>i && j>(s[i]-'0')){
                    swap(s[i], s[v[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};