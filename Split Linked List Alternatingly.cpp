class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<Node*> res(2);
        Node *h1=head, *h2=head->next;
        res[0] = h1;
        res[1] = h2;
        while(h1 && h2){
            h1->next = h2->next;
            h1 = h1->next;
            if(!h1) break;
            h2->next = h1->next;
            h2 = h2->next;
        }
        
        return res;
    }
};