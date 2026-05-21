class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        while(n != 1){
            if(n%2 == 0)
                return false;
            n /= 2;
        }
        return true;
    }
};