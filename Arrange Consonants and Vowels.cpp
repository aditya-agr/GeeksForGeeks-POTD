class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        Node*vwl=new Node(0);
        Node*cnt=new Node(0);
        Node*cnth=cnt, *vwlh=vwl;
        unordered_set<char> st={'a','e','i','o','u'};
        
        if(!head || !head->next)
            return head;
        while(head){
            if(st.find(head->data) != st.end()){
                vwl->next = head;
                vwl = vwl->next;
            }
            else{
                cnt->next = head;
                cnt = cnt->next;
            }
            head = head->next;
        }
        vwl->next = cnth->next;
        cnt->next = NULL;
        return vwlh->next;
    }
};