class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int res=0;
        for(int i=4; i<=n; i++){
            int tmp=i;
            while(tmp){
                if(tmp%10==4){ 
                    res++;
                    break;
                }
                tmp /= 10;
            }
        }
        return res;
    }
};