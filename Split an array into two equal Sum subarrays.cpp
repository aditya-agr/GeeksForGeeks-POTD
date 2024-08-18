class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long int tsum=0, sum=0;
        for(int i : arr)
            tsum += i;
        for(int i : arr){
            sum += i;
            if(tsum-sum == sum)
                return true;
        }
        return false;
    }
};
