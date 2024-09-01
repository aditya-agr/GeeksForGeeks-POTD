class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int sum1=0, sum2=0, ans=0;
        int n=arr1.size(), m=arr2.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j])
                sum1 += arr1[i++];
            else if(arr1[i]>arr2[j])
                sum2 += arr2[j++];
            else{
                ans += max(sum1, sum2) + arr1[i];
                i++;
                j++;
                sum1=0, sum2=0;
            }
        }
        while(i<n)
            sum1 += arr1[i++];
        while(j<m)
            sum2 += arr2[j++];
        return ans + max(sum1, sum2);
    }
};