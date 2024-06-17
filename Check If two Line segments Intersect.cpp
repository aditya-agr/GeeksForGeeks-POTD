class Solution {
  public:
    bool onSeg(int p[], int q[], int r[]){
        if(r[0]<=max(p[0],q[0]) && r[0]>=min(p[0],q[0]) && 
        r[1]<=max(p[1],q[1]) && r[1]>=min(p[1],q[1]))
            return true;
        return false;
    }
    int orient(int p[], int q[], int r[]){
        long long s1 = 1LL*(q[1]-p[1])*(r[0]-q[0]) - 1LL*(r[1]-q[1])*(q[0]-p[0]);
        if(s1==0)
            return 0;
        return s1 > 0 ? 1 : 2;
    }
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        int o1 = orient(p1,q1,p2);
        int o2 = orient(p1,q1,q2);
        int o3 = orient(p2,q2,p1);
        int o4 = orient(p2,q2,q1);
        
        if(o1!=o2 && o3!=o4)
            return "true";
        
        if(!o1 && onSeg(p1,q1,p2)) return "true";
        if(!o2 && onSeg(p1,q1,q2)) return "true";
        if(!o3 && onSeg(p2,q2,p1)) return "true";
        if(!o4 && onSeg(p2,q2,q1)) return "true";
        return "false";
    }
};