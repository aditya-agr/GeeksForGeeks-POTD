class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> cnt, end;
        int n = arr.size();
        for(int x : arr)
            cnt[x]++;
        for(int i=0; i<n; i++){
            if(cnt[arr[i]] == 0)
                continue;
            
            if(end[arr[i]-1] > 0){
                end[arr[i]-1]--;
                end[arr[i]]++;
                cnt[arr[i]]--;
            }
            else{
                bool possible = true;
                int num = arr[i];
                for(int i=0; i<k; i++){
                    if(cnt[num+i] == 0){
                        possible = false;
                        break;
                    }
                }
                if(!possible)
                    return false;
                for(int i=0; i<k; i++)
                    cnt[num+i]--;
                    
                end[num+k-1]++;
            }
        }
        return true;
    }
};
