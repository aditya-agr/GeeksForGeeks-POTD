class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        Node *st=head, *ed=head;
        int sum=0;
        for(int i=0; i<n; i++){
            sum += ed->data;
            ed = ed->next;
        }
        while(ed){
            sum -= st->data;
            sum += ed->data;
            ed = ed->next;
            st = st->next;
        }
        return sum;
    }
};