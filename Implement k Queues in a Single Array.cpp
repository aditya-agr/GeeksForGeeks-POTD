class kQueues {
    int idx;
    vector<int> arr;
    vector<int> next;
    vector<int> f;
    vector<int> r;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        idx = 0;
        arr.resize(n);
        next.resize(n);
        f.resize(k);
        r.resize(k);
        
        for(int i=0; i<n-1; i++)
            next[i] = i+1;
        next[n-1] = -1;
        
        for(int i=0; i<k; i++)
            f[i] = r[i] = -1;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(idx == -1)  
            return;
        if(r[i] == -1){
            f[i] = r[i] = idx;
            arr[idx] = x;
            idx = next[idx];
        }
        else{
            arr[idx] = x;
            next[r[i]] = idx;
            r[i] = idx;
            idx = next[idx];
        }
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(r[i] == -1)
            return -1;
        if(r[i] == f[i]){
            int val = arr[f[i]];
            next[f[i]] = idx;
            idx = f[i];
            r[i] = f[i] = -1;
            return val;
        }
        else{
            int val = arr[f[i]];
            int temp = f[i];
            f[i] = next[f[i]];
            next[temp] = idx;
            idx = temp;
            return val;
        }
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return (r[i] == -1);
    }

    bool isFull() {
        // check if array is full
        return (idx == -1);
    }
};
