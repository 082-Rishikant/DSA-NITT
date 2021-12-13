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

void deletion(node* &head, int val)
{
    node* temp=head;
    if(head->data==val)
    {
        head=head->next;
        delete temp;
        return;
    }
    while(temp->next!=NULL)
    {
        if((temp->next)->data==val)
        {
            node* toDelte=temp->next;
            temp->next=toDelte->next;
            delete toDelte;
            return;
        }
        temp=temp->next;
    }
    cout<<"Not Found\n";
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
    
    int datatoDelete=5;
    deletion(head,datatoDelete);
    
    display(head);
    return 0;
}