class Solution {
  public:
    int getCount(int n) {
      // code here
      if(n<=2)return 0;
      int ans = 1;
      int start = 1;
      int end = 1;
      int count = 0;
      
      int a = n/2;
      a++;
      
      while(end<=a && start<=end){
          
          if(ans==n) count++;
          
          if(ans<=n){
              end++;
              ans+=end;
          }
          else{
              ans-=start;
              start++;
          }
          
      }
      
      return count;
    }
};