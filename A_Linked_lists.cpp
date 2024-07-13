===========================================Singly linked list===========================
                                            Insertion in SLL
1. Insert at the beginning
==========================
newNode->next = head;
head = newNode;

2. Insert at the End
======================
while(temp->next != NULL){
  temp = temp->next;
}
temp->next = newNode;

3. Insert at the Middle
======================
for(int i=2; i < position; i++) {
  if(temp->next != NULL) {
    temp = temp->next;
  }
}
newNode->next = temp->next;
temp->next = newNode;
                                          Deletion in SLL
1.Delete from beginning
======================
head = head->next;

2. Delete from end
======================
Traverse to second last element
Change its next pointer to null
struct node* temp = head;
while(temp->next->next!=NULL){
  temp = temp->next;
}
temp->next = NULL;

3. Delete from middle
======================
Traverse to element before the element to be deleted
Change next pointers to exclude the node from the chain
for(int i=2; i< position; i++) {
  if(temp->next!=NULL) {
    temp = temp->next;
  }
}

temp->next = temp->next->next;
====================================================Sorting Linkedlist=================================================================
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL){ 
            return head;
        }
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;  
            fast = fast ->next ->next;  
            
        }   
        temp -> next = NULL;           
        
        ListNode* l1 = sortList(head);    
        ListNode* l2 = sortList(slow);
        
        return mergelist(l1, l2);         
            
    }
    ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
};
==========================================================Double linked list ============================
                                                          Insertion
  1.Insert at beginning
  void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}
2.Insert at the End
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
3. Insert after a Given Node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) {
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}
                                              Deletion
Delete a Node
Pseudocode:

If the node to be deleted is the head, set head to the node's next.
If the node's next is not null, set its next's prev to the node's prev.
If the node's prev is not null, set its prev's next to the node's next.
Delete the node.

2. Delete from the Beginning
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

3. Delete from end
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}
====================================================Reversing linked list==========================================
  SLL
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
DLL
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
======================================================================================================
  

