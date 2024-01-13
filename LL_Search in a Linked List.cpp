int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int>* temp=head;
    int f=0;
    while(temp!=NULL)
    {
        if(temp->data == k) 
        {
            f=1;
            break;
        }
        temp=temp->next;
    }
    if(f==0) return 0;
    return 1;
}
