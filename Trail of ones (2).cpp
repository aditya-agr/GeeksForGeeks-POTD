class Solution {
  public:
    int countConsec(int n) {
        // code here
        int a=0, b=1, c=1;
        int curr=1, prev=1;
        for(int i=3; i<=n; i++){
            c = a+b;
            curr = prev*2+c;
            prev = curr;
            a = b;
            b = c;
        }
        return curr;
    }
};