#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int n)
    {
        data=n;
        next=NULL;
    }
};

void insertAtTail(node* &head, int data) // head pointer pass by reference Because we
{                                        // are editing Linked List.
    node* n=new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    return;
}

void display(node* head) // head pointer pass by value beacuse we are not editing LL
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void iterativeReverseLL(node* &head)
{
    node* prev=NULL;
    node* current=head;
    node* Next;
    while(current!=NULL)
    {
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    head=prev;
    return;
}

void recursiveReverseLL(node* &head, node* current, node* prev)
{
    if(current==NULL)
    {
        cout<<"Null LinkedList\n";
        return;
    }
    if(current->next==NULL)
    {
        head=current;
        current->next=prev;
        return;
    }
    recursiveReverseLL(head, current->next, current);
    current->next=prev;
    return;
}

int main()
{
    node * head=NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    
    // iterativeReverseLL(head);
    // display(head);

    recursiveReverseLL(head, head, NULL);
    display(head);
    
    return 0;
}