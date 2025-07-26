class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int ele1=INT_MIN, ele2=INT_MIN;
        int cnt1=0, cnt2=0;
        for(int x : arr){
            if(cnt1==0 && x!=ele2){
                cnt1++;
                ele1 = x;
            }
            else if(cnt2==0 && x!=ele1){
                cnt2++;
                ele2 = x;
            }
            else if(x==ele1)
                cnt1++;
            else if(x==ele2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int x : arr){
            if(x == ele1)
                cnt1++;
            if(x == ele2)
                cnt2++;
        }
        vector<int> res;
        if(cnt1 > n/3) 
            res.push_back(ele1);
        if(cnt2 > n/3)
            res.push_back(ele2);
        sort(res.begin(), res.end());
        return res;
    }
    
};