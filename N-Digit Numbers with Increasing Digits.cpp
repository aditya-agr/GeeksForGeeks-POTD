class Solution {
  public:
    void solve(string s, int n, vector<int> &res){
        if(n == 0){
            int num = stoi(s);
            res.push_back(num);
            return;
        }
        for(int i=s.back()-'0'+1; i<=9; i++){
            char c = '0'+i;
            solve(s+c, n-1, res);
        }
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int> res;
        if(n > 9)
            return res;
            
        if(n == 1){
            for(int i=0; i<=9; i++)
                res.push_back(i);
            return res;
        }
        string curr = "";
        for(int i=1; i<=9; i++){
            char c = '0'+i;
            solve(curr+c, n-1, res);
        }
        return res;
    }
};