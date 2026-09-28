class SegmentTree{
  public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n);
    }
    void buildTree(int i, int l, int r, vector<int> &arr){
        if(l == r){
            tree[i] = arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(2*i+1, l, mid, arr);
        buildTree(2*i+2, mid+1, r, arr);
        tree[i] = __gcd(tree[2*i+1], tree[2*i+2]);
    }
    int query(int i, int l, int r, int &st, int &ed){
        if(l > ed || r < st)
            return -1;
        if(l >= st && r <= ed)
            return tree[i];
        int mid = l + (r-l)/2;
        int res;
        int left = query(2*i+1, l, mid, st, ed);
        int right = query(2*i+2, mid+1, r, st, ed);
        if(left == -1)
            return right;
        if(right == -1)
            return left;
        return __gcd(left, right);
    }
    void update(int i, int l, int r, int &idx, int &val){
        if(l == r){
            tree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid)
            update(2*i+1, l, mid, idx, val);
        else
            update(2*i+2, mid+1, r, idx, val);
        tree[i] = __gcd(tree[2*i+1], tree[2*i+2]);
    }
    
};
class Solution {
  public:
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        SegmentTree seg(n);
        seg.buildTree(0, 0, n-1, arr);
        
        vector<int> res;
        for(vector<int> q : queries){
            if(q[0] == 0){
                int cur = seg.query(0, 0, n-1, q[1], q[2]);
                res.push_back(cur);
            }
            else
                seg.update(0, 0, n-1, q[1], q[2]);
        }
        return res;
    }
};