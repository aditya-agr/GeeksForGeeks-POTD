class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n=arr1.size();
        int i=0, j=0, cnt=0;
        int sum = 0;
        while(i<n && j<n){
            if(arr1[i]<arr2[j]){
                cnt++;
                if(cnt==n || cnt==(n+1))
                    sum += arr1[i];
                i++;
            }
            else{
                cnt++;
                if(cnt==n || cnt==(n+1))
                    sum += arr2[j];
                j++;
            }
        }
        while(i<n){
            cnt++;
            if(cnt==n || cnt==(n+1))
                sum += arr1[i];
            i++;
        }
        while(j<n){
            cnt++;
            if(cnt==n || cnt==(n+1))
                sum += arr2[j];
            j++;
        }
        return sum;
    }
};