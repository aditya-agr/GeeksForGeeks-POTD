class Solution {
  public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int countBalanced(vector<string>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, sum = 0;
        for(int i=0; i<n; i++){
            for(char c : arr[i]){
                if(isVowel(c))
                    sum++;
                else
                    sum--;
            }
            res += mp[sum];
            mp[sum]++;
        }
        return res;
    }
};