class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int> preSum(n+1);
        for(int x : citations){
            if(x >= n) preSum[n]++;
            else preSum[x]++;
        }
        for(int i=n-1; i>=0; i--)
            preSum[i] += preSum[i+1];
            
        for(int i=n; i>0; i--)
            if(preSum[i]>=i)
                return i;
                
        return 0;
    }
};