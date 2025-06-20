class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n%k)
            return false;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        int i=0;
        while(i<n){
            if(mp[arr[i]]){
                int val=arr[i];
                for(int j=0; j<k; j++){
                    if(mp[val])
                        mp[val]--;
                    else
                        return false;
                    val++;
                }
            }
            i++;
        }
        return true;
    }
};