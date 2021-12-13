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

void insertAtHead(node* &head, int data)  // head pointer pass by reference Because we are 
{                                         // editing Linked List
    node* n=new node(data);
    n->next=head;
    head=n;
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

void search(node* head, int val) // head pointer pass by value beacuse we are not editing LL
{
    while (head!=NULL)
    {
        if(head->data==val)
        {
            cout<<"Found\n";
            return;
        }
        head=head->next;
    }
    cout<<"Not Found\n";
}

int main()
{
    node * head=NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    insertAtHead(head, 5);
    display(head);

    int val=6;
    search(head, val);
    return 0;
}