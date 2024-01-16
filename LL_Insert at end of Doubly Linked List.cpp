Node * insertAtTail(Node *head, int k) {
    // Write your code here
    if(head==NULL) return new Node(k);
    Node* temp=head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    Node* newNode = new Node(k);
    temp->next = newNode;
    newNode->prev=temp;
    return head;
}
