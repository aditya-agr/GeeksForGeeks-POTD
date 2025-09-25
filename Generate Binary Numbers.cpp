class Solution {
  public:
    string to_binary(int num){
        string s = "";
        while(num){
            if(num%2)
                s = "1" + s;
            else
                s = "0" + s;
            num /= 2;
        }
        return s;
    }
    vector<string> generateBinary(int n) {
        // code here
        vector<string> res;
        for(int i=1; i<=n; i++){
            string num = to_binary(i);
            res.push_back(num);
        }
        return res;
    }
};