Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* temp=head;
    int x=0;
    while(temp!=NULL)
    {
        temp->data=arr[x];
        x++;
        temp->next=next;
    }
    return head;
}
