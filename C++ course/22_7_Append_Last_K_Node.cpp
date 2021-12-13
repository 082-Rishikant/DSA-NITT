#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int n)
    {
        data=n;
        next=NULL;
    }
};

void insertAtTail(node* &head, int d)
{
    node* newNode;
    newNode=new node(d);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void appendLastK(node* &head, int k)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    node* newHead;
    node* newTail;
    node* Tail;
    int count=1;
    temp=head;
    while(temp->next!=NULL)
    {
        if(count==(l-k))
        {
            newTail=temp;
        }
        if(count==(l-k+1))
        {
            newHead=temp;
        }
        temp=temp->next;
        count++;
    }
    Tail=temp;

    newTail->next=NULL;
    Tail->next=head;
    head=newHead;
    return;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);

    appendLastK(head, 3);
    display(head); // Display After Appending last k Node to starting of the node
    return 0;
}