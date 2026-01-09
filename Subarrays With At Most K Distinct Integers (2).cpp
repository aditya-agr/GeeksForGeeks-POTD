class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int i=0, j=0;
        int dist = 0, res = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[arr[j]]++;
            if(mp[arr[j]] == 1)
                dist++;
            while(dist > k){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                    dist--;
                i++;
            }
            res += j-i+1;
            j++;
        }
        return res;
    }
};