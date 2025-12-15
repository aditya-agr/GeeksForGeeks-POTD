class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int  odd=0,even=0;
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
           if(i%2==0){
               even+=arr[i];
           }
           else odd+=arr[i];
        }
        int leftOdd=0,leftEven=0,ans=0;
        for(int i=0;i<n;i++){
           if(i%2==0){
               even-=arr[i];
              if(leftOdd+even==leftEven+odd) ans++; 
              leftEven+=arr[i];
           }
           else{
             odd-=arr[i];
             if(leftOdd+even==leftEven+odd) ans++;
             leftOdd+=arr[i];
           }
          
        }
        return ans;
    }
};s