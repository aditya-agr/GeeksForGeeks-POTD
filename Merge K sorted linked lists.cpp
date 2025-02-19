#define P pair<int, Node*>

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<P, vector<P>, greater<P>> pq;
        for(Node* curr : arr)
            pq.push({curr->data, curr});
        Node* head = new Node(0);
        Node* temp = head;
        while(!pq.empty()){
            Node* curr = pq.top().second;
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
            if(curr)
                pq.push({curr->data, curr});
        }
        return head->next;
    }
};