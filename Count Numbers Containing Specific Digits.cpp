class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        bool zero = false;
        for(int x : arr)
            if(x == 0)
                zero = true;
        
        int m = arr.size();
        int tot = 9 * pow(10, n-1);
                
        int ways = 9 - (m - zero);
        while(n>1){
            ways *= (10-m);
            n--;
        }
        return tot - ways;
    }
};
