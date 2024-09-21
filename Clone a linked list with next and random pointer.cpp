class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
        Node *temp = head;
        while(temp){
            Node *curr = new Node(temp->data);
            curr->next = temp->next;
            temp->next = curr;
            temp = curr->next;
        }
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* res = new Node(0), *curr=res;
        temp = head;
        while(temp){
            curr->next = temp->next;
            curr = curr->next;
            temp->next = curr->next;
            temp = temp->next;
        }
        return res->next;
    }
};