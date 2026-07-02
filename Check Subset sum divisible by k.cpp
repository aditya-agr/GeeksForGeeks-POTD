class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        vector<bool> vis(k, false);
        for(int x : arr){
            int rem = x%k;
            if(rem == 0)
                return true;
            vector<bool> newVis(vis);
            newVis[rem] = true;
            for(int i=0; i<k; i++){
                if(vis[i]){
                    int rem2 = (rem + i)%k; 
                    if(rem2 == 0)
                        return true;
                    newVis[rem2]  = true;
                }
            }
            vis = newVis;
        }
        return vis[0];
    }
};