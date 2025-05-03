vector<int> sieve(){
    int n = 10009;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i)
                prime[j] = false;
        }
    }
    vector<int> res;
    for(int i=2; i<=n; i++)
        if(prime[i])
            res.push_back(i);
    return res;
}
class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
        vector<int> primes = sieve();
        Node* temp = head;
        while(temp){
            int num = temp->val;
            int idx = lower_bound(primes.begin(), primes.end(), num) - primes.begin();
            if(primes[idx] != num){
                if(idx>0 && num-primes[idx-1] <= primes[idx]-num)
                    temp->val = primes[idx-1];
                else
                    temp->val = primes[idx];
            }
            temp = temp->next;
        }
        return head;
    }
};