int length(Node *head)
{
	//Write your code here
    Node *temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
