//swap the links between the nodes.
Node* reverseDLL(Node* head)
{   
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
   Node* temp=NULL;
   Node* curr=head;
   while(curr!=NULL)
   {
       temp=curr->prev;
       curr->prev=curr->next;
       curr->next=temp;
       curr=curr->prev;
   }
   
   return temp->prev;
}

