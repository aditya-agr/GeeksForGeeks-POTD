class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int tot = 0, tank = 0;
        int st = 0;
        for(int i=0; i<n; i++){
            int rem = gas[i]-cost[i];
            tot += rem;
            tank += rem;
            if(tank < 0){
                st = i+1;
                tank = 0;
            }
        }
        return (tot < 0) ? -1 : st;
    }
};