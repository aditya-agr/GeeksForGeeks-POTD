class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        long long sum1=0, sum2=0;
        for(int i=0; i<n; i++)
            sum1 += a[i];
        for(int i=0; i<m; i++)
            sum2 += b[i];
        long long diff = sum1-sum2;
        if(diff%2)
            return -1;
        diff /= 2;
        sort(a, a+n);
        sort(b, b+m);
        int i=0, j=0;
        while(i<n && j<m){
            if(a[i]-b[j]==diff)
                return 1;
            else if(a[i]-b[j]<diff)
                i++;
            else
                j++;
        }
        return -1;
    }
};