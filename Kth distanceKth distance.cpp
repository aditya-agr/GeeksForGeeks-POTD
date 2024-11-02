
class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_map<int, int> mp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
            else{
                if(i-mp[arr[i]] <= k)
                    return true;
                mp[arr[i]] = i;
            }
        }
        return false;
    }
};