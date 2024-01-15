//What if an array is given to u and then how can u construct a doubly linked list.
Node* constructDLL(vector<int>& arr) {
    // Write your code here
    Node* temp=new Node(arr[0]);
    Node* prev=temp;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return temp;

}
