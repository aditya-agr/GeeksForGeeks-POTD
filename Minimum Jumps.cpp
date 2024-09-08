class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int jumps = 0;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            //i-->maxiInd
            int maxiInd = -1;
            int maxi = INT_MIN;
            for(int j=i+1;j<i+1+arr[i];j++){
                if(j >= n-1){
                    //1 jump for i-->n-1
                    jumps++;
                    return jumps;
                }
                if(maxi <= arr[j]+j){
                    maxi = arr[j]+j;
                    maxiInd = j;
                }
            }
            // 1 jump for i--> maxiInd
            jumps++;
            i = maxiInd-1;
            if(maxiInd == -1){
                //if you are at ind which is zero valued
                return -1;
            }
        }
        
        return jumps;
    }
};
