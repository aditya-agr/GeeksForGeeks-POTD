class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here
        long long res=1;
        for(int x : arr){
            if(x>res)
                return res;
            res += x;
        }
        return res;
    }
    
};