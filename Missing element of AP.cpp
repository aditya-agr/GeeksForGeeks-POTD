class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i=0; i<n-1; i++)
            mp[arr[i+1]-arr[i]]++;
        
        int diff = -1;
        for(auto it : mp)
            if(it.second == 1)
                diff = it.first;
        
        for(int i=0; i<n-1; i++){
            if(arr[i+1] - arr[i] == diff)
                return (arr[i+1]+arr[i])/2;
        }
        diff = arr[1]-arr[0];
        return arr[n-1]+diff;
    }
};