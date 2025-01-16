class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for(int i=0; i<n; i++)
            if(arr[i] == 0)
                arr[i] = -1;
        unordered_map<int, int> mp;
        mp[0] = 0;
        int curr = 0, res = 0;
        for(int i=0; i<n; i++){
            curr += arr[i];
            if(mp.find(curr) == mp.end())
                mp[curr] = i+1;
            else
                res = max(res, i-mp[curr]+1);
        }
        return res;
    }
};