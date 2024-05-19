class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int i=upper_bound(arr, arr+n, k)-arr;
        int ans;
        if(abs(arr[i]-k) <= abs(arr[i-1]-k))
            ans = arr[i];
        else
            ans = arr[i-1];
        return ans;
    } 
};