class LRUCache {
  private:
    vector<pair<int, int>> cache;
    int n;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        n = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return val;
            }
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() == n){
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }
        else
            cache.push_back({key, value});
    }
};