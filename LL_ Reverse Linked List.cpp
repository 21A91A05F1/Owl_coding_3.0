Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node* curr=head;
    Node* temp=curr->next;
    Node* prev=NULL;
    if(head==NULL or head->next==NULL) return NULL;
    while(curr)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
