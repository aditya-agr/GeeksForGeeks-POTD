class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int sum=0, tmp=n;
        while(tmp){
            int rem = tmp%10;
            sum = sum + (rem*rem*rem);
            tmp /= 10;
        }
        if(n==sum)
            return "true";
        return "false";
    }
};