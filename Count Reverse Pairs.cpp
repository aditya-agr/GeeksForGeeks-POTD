class Solution {
  public:
    void merge(vector<int> &arr, int l, int h, int mid){
        int left = l, right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=h){
            if(arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while(left<=mid)
            temp.push_back(arr[left++]);
        while(right<=h)
            temp.push_back(arr[right++]);
        for(int i=l; i<=h; i++)
            arr[i] = temp[i-l];
    }
    
    int count(vector<int> &arr, int l, int h, int mid){
        int cnt = 0, left = l, right = mid+1;
        while(left <= mid){
            while(right<=h && arr[left]/2.0 > arr[right])
                right++;
            cnt += (right-mid-1);
            left++;
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int l, int h){
        if(l>=h)
            return 0;
        int mid = l + (h-l)/2;
        int cnt = 0;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid+1, h);
        cnt += count(arr, l, h, mid);
        merge(arr, l, h, mid);
        return cnt;
    }
    
    int countRevPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};