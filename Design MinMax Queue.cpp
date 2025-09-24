class SpecialQueue {
    queue<int> q;
    priority_queue<int> mxpq;
    priority_queue<int, vector<int>, greater<int>> mnpq;
    unordered_map<int, int> mp;
    
  public:
  
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        mxpq.push(x);
        mnpq.push(x);
        mp[x]++;
    }

    void dequeue() {
        // Remove element from the queue
        int x = q.front();
        q.pop();
        mp[x]--;
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        while(!mnpq.empty() && mp[mnpq.top()]==0){
            mnpq.pop();
        }
        return mnpq.empty() ? -1 : mnpq.top();
    }

    int getMax() {
        // Get maximum element
        while(!mxpq.empty() && mp[mxpq.top()]==0){
            mxpq.pop();
        }
        return mxpq.empty() ? -1 : mxpq.top();
    }
};