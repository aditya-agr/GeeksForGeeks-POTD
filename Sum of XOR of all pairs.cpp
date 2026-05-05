class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        long long sum = 0;
        int n = arr.size();
        for (int i = 0; i < 32; i++) {
            long long oneCnt = 0, zeroCnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] % 2 == 0)
                    zeroCnt++;
                else
                    oneCnt++;
                
                arr[j] /= 2;
            }
            sum += (zeroCnt * oneCnt) * (1 << i);
        }
        return sum;
    }
};