bool has_cycle(SinglyLinkedListNode* head) {

    if(head==NULL) return false;
    SinglyLinkedListNode* slow=head;
    SinglyLinkedListNode* fast=head;
    
    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) return true;
    }
    return false;

}
