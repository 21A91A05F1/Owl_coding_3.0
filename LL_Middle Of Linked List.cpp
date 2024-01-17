Node *findMiddle(Node *head) {
    // Write your code here
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}
