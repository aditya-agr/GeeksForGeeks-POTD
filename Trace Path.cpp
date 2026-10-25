class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        int i=0, j=0;
        int mxx=0, mnx=0, mxy=0, mny=0;
        int k = s.length();
        for(int x=0; x<k; x++){
            if(s[x] == 'L'){
                j -= 1;
                mxy = max(mxy, j);
                mny = min(mny, j);
            }
            else if(s[x] == 'R'){
                j += 1;
                mxy = max(mxy, j);
                mny = min(mny, j);
            }
            else if(s[x] == 'D'){
                i -= 1;
                mxx = max(mxx, i);
                mnx = min(mnx, i);
            }
            else if(s[x] == 'U'){
                i += 1;
                mxx = max(mxx, i);
                mnx = min(mnx, i);
            }
        }
        int dx = mxx - mnx;
        int dy = mxy - mny;
        return dx<n && dy<m;
    }
};