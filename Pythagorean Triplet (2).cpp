class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        // sort(arr.begin(), arr.end());
        // int n = arr.size();
        // for(int i=0; i<n; i++){
        //     arr[i] *= arr[i];
        // }
        // for(int a=n-1; a>1; a--){
        //     int b=0, c=a-1;
        //     while(b<c){
        //         int cur = arr[b]+arr[c];
        //         if(cur < arr[a])
        //             b++;
        //         else if(cur > arr[a])
        //             c--;
        //         else
        //             return true;
        //     }
        // }
        // return false;
        
        
        int mx = *max_element(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        vector<int> vis(mx+1);
        int n = arr.size();
        for(int i=0; i<n; i++)
            vis[arr[i]]++;
        
        for(int i=1; i<=mx; i++){
            if(!vis[i])
                continue;
            for(int j=i+1; j<=mx; j++){
                if(!vis[j])
                    continue;
                int cur = i*i + j*j;
                int sq = sqrt(cur);
                if(sq*sq == cur && sq<=mx && vis[sq])
                    return true;
            }
        }
        return false;
    }
};