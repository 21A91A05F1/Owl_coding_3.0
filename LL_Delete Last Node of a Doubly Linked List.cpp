
Node * deleteLastNode(Node *head) {
    // Write your code here
    if(head==NULL or head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    Node* newtail=temp->prev;
    newtail->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
