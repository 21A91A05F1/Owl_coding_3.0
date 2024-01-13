Node* insertAtFirst(Node* head, int newValue) {
    // Write your code here
    Node* temp=new Node(newValue);
    temp->next=head;
    head=temp;
    return head;

}
