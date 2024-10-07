struct Node *insert(struct Node *head, int data) {
    // Code here
    Node *temp = new Node(data);
    temp->npx = head;
    if(head)
        head->npx = XOR(temp, head->npx);
    return temp;
}

vector<int> getList(struct Node *head) {
    // Code here
    Node* curr = head, *nxt = NULL, *prev = NULL;
    vector<int> res;
    while(curr){
        res.push_back(curr->data);
        nxt = XOR(prev, curr->npx);
        prev = curr;
        curr = nxt;
    }
    return res;
}