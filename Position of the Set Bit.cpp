class Solution {
  public:
    int findPosition(int n) {
        // code here
        int max = 1e8+1;
        int it = 1, l = 1;
        while(it < max){
            if(it == n)
                return l;
            it *= 2;
            l++;
        }
        return -1;
    }
};