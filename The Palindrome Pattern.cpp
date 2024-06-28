class Solution {
  public:
    bool isPal(string s){
        int n = s.length();
        for(int i=0; i<n/2; i++)
            if(s[i]!=s[n-i-1])
                return false;
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<n; j++)
                s += ('0'+arr[i][j]);
            if(isPal(s))
                return to_string(i) + " R";
        }
        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<n; j++)
                s += ('0'+arr[j][i]);
            if(isPal(s))
                return to_string(i) + " C";
        }
        return "-1";
    }
};
