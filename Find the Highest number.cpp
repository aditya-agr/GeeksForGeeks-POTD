class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int n = a.size();
        int i=0, j=n-1;
        int res=0;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(a[mid] > res)
                res = a[mid];
            if(a[mid-1] > a[mid])
                j=mid-1;
            else
                i=mid+1;
        }
        return res;
    }
};
