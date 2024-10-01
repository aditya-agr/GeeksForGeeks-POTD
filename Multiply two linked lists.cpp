class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long n1=0, n2=0;
        long long m = 1e9+7;
        while(first){
            n1 *= 10;
            n1 += first->data;
            first = first->next;
        }
        while(second){
            n2 *= 10;
            n2 += second->data;
            second = second->next;
        }
        return (n1*n2)%m;
    }
};