class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        vector<int> res;
        int cnt1=0, cnt2=0, ele1=0, ele2=0;
        for(int i=0; i<n; i++){
            if(cnt1==0 && arr[i]!=ele2){
                cnt1++;
                ele1 = arr[i];
            }
            else if(cnt2==0 && arr[i]!=ele1){
                cnt2++;
                ele2 = arr[i];
            }
            else if(arr[i] == ele1)
                cnt1++;
            else if(arr[i] == ele2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int x : arr){
            if(x == ele1) cnt1++;
            if(x == ele2) cnt2++;
        }
        if(cnt1>n/3) res.push_back(ele1);
        if(cnt2>n/3) res.push_back(ele2);
        sort(res.begin(), res.end());
        return res;
    }
};