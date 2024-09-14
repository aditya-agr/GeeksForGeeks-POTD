class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos;
        vector<int>neg;
        for (int i:arr){
            if (i>=0)
                pos.push_back(i);
            else
                neg .push_back(i);
        }
        
        int n=arr.size();
        int m=pos.size();
        int p=neg.size();

        vector<int>result;
        int posi=0;
        int negi=0;
        for(int i=0;i<n;i++){
             if (posi<m)
                   result.push_back(pos[posi++]);
             if (negi<p)
                  result.push_back(neg[negi++]);
        }
        arr = result;
    }
};