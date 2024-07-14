class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ve;
        Node* temp1=head;
      
        
        while(temp1!=NULL)
        {
            Node* temp2=temp1->next;
            while(temp2!=NULL)
            {
                if(temp1->data+temp2->data ==target) 
                {
                    ve.push_back({temp1->data,temp2->data});
                }
                if(temp1->data+temp2->data > target) break;
                
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return ve;
    }
};

Optimised:
class Solution
{
public:
    Node* findtail(Node* head)
    {
        Node* tail=head;
        while(tail->next!=NULL) tail=tail->next;
        return tail;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ve;
        Node* left=head;
        Node* right=findtail(head);
        
        while(left->data < right->data)
        {
            if(left->data+right->data == target)
            {
                ve.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(left->data + right->data > target) right=right->prev;
            else left=left->next;
        }
        return ve;
    }
};
