class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        Node *temp = head;
        while(temp){
            if(temp->data == 0)
                cnt0++;
            else if(temp->data == 1)
                cnt1++;
            else 
                cnt2++;
            temp = temp->next;
        }
        temp = head;
        while(cnt0){
            temp->data = 0;
            temp = temp->next;
            cnt0--;
        }
        while(cnt1){
            temp->data = 1;
            temp = temp->next;
            cnt1--;
        }
        while(cnt2){
            temp->data = 2;
            temp = temp->next;
            cnt2--;
        }
        return head;
    }
};