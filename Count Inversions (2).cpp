class Solution {
  public:
    int merge(vector<int> &arr, int l, int h, int mid){
        int left = l;
        int right = mid+1;
        vector<int> temp;
        int cnt = 0;
        while(left<=mid && right<=h){
            if(arr[left]<=arr[right])
                temp.push_back(arr[left++]);
            else{
                temp.push_back(arr[right++]);
                cnt += (mid-left+1);
            }
        }
        while(left<=mid)
            temp.push_back(arr[left++]);
        while(right<=h)
            temp.push_back(arr[right++]);
        
        for(int i=l; i<=h; i++)
            arr[i] = temp[i-l];
        return cnt;
    }
    int Mergesort(vector<int>& arr, int l, int h){
        if(l >= h)
            return 0;
        int mid = l+(h-l)/2;
        int cnt = Mergesort(arr, l, mid);
        cnt += Mergesort(arr, mid+1, h);
        cnt += merge(arr, l, h, mid);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        return Mergesort(arr, 0, n-1);
    }
};