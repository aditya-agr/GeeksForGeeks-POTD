class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        if(n==1 | n==2)
            return {n}; 
        vector<int> res(n-1);
        iota(res.begin(), res.end(), 1);
        
        if(n%4==1)
            res.pop_back();
        else if(n%4 == 2)
            res.erase(res.begin());
            
        if(n%4!=3)
            res.push_back(n);
        return res;
    }
};
