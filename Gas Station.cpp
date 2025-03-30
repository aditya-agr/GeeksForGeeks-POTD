class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int tot = 0;
        int req = 0;
        int n = gas.size();
        for(int i=0; i<n; i++){
            tot += gas[i];
            req += cost[i];
        }
        if(tot < req)
            return -1;
        int curr = 0;
        int idx = 0;
        for(int i=0; i<n; i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                idx = i + 1;
                curr = 0;
            }
        }
        return idx;
    }
};