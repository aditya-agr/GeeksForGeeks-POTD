class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)temp.push_back({abs(arr[i]-brr[i]),i});
        sort(temp.begin(),temp.end());
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            int index = temp[i].second;
            if(arr[index]>brr[index]){
                if(x){
                    ans+=arr[index];
                    x--;
                }
                else{
                    ans+=brr[index];
                    y--;
                }
            }
            else{
                if(y){
                    ans+=brr[index];
                    y--;
                }
                else{
                    ans+=arr[index];
                    x--;
                }
            }
        }
        return ans;
    }
};