class Solution {
  public:
    int binary_search(int target, vector<int> &brr){
        int l=0, h=brr.size()-1, idx=-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(brr[mid]<=target){
                l = mid+1;
                idx = mid;
            }
            else
                h = mid-1;
        }
        return idx;
        
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        int m = brr.size();
        sort(brr.begin(), brr.end());
        int cnt1=0, cnt2=0, cnt34=0;
        for(int it : brr){
            if(it==1) cnt1++;
            else if(it==2) cnt2++;
            else if(it==3 || it==4) cnt34++;
        }
        long long ans=0;
        for(int x : arr){
            if(x==1) continue;
            int idx = binary_search(x, brr);
            ans += (m-idx-1);
            ans += cnt1;
            if(x==3) ans += cnt2;
            if(x==2) ans -= cnt34;
        }
        return ans;
    }
};