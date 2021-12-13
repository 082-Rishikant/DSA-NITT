#include<iostream>
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

void insertAtTail(node* &head, int d)
{
    node* n=new node(d);
    if(head==NULL)
    {
        head=n;
        return;
    }
    else
    {
        node * temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        return;
    }
    
}

void insertAtHead(node* &head, int d)
{
    node* n=new node(d);
    n->next=head;
    head=n;
    return;
}

void display(node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
    return;
}

node* reverse_K_Node(node * &head, int k)
{
    node* prev=NULL;
    node* curr=head;
    node* nexptr;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nexptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nexptr;
        count++;
    }
    if(curr!=NULL)
    {
        head->next=reverse_K_Node(curr, k);
    }
    return prev;
}

int main()
{
    node* head=NULL;
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    insertAtTail(head, 70);
    insertAtHead(head, 20);
    insertAtHead(head, 22);
    insertAtHead(head, 24);
    display(head);
    cout<<endl;

    int k=2;
    head=reverse_K_Node(head, k);
    display(head);
    return 0;
}