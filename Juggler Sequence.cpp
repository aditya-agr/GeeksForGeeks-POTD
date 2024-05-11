class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> res;
        res.push_back(n);
        while(n!=1){
            if(n%2)
                n = n*sqrt(n);
            else
                n = sqrt(n);
            res.push_back(n);
        }
        return res;
    }
};