class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        // int n = arr.size();
        // for(int i=0; i<n; i++)
        //     arr[i] *= arr[i];
            
        // sort(arr.begin(), arr.end());
        
        // for(int i=n-1; i>=2; i--){
        //     int j=0, k=i-1;
        //     int sum = arr[i];
        //     while(j<k){
        //         if(arr[j]+arr[k] == sum)
        //             return true;
        //         else if(arr[j]+arr[k] > sum)
        //             k--;
        //         else
        //             j++;
        //     }
        // }
        // return false;
        
        int mx = *max_element(arr.begin(), arr.end());
        vector<bool> vis(mx+1);
        int n = arr.size();
        for(int i=0; i<n; i++)
            vis[arr[i]] = true;
        
        for(int i=1; i<=mx; i++){
            if(!vis[i])
                continue;
            for(int j=1; j<=mx; j++){
                if(!vis[j])
                    continue;
                int c = sqrt(i*i + j*j);
                if(c*c != i*i+j*j || c>mx)
                    continue;
                if(vis[c])
                    return true;
            }
        }
        return false;
    }
};                       