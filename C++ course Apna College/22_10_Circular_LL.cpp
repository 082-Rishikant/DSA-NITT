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

void insertAtHead(node* &head, int d)
{
    node* newNode;
    newNode=new node(d);
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
        return;
    }
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    head=newNode;
}

void insertAtTail(node* &head, int d)
{
    node* newNode;
    newNode=new node(d);
    if(head==NULL)
    {
        insertAtHead(head, d);
        return;
    }
    node* temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return;
}

void displayCircular(node* head)
{
    // node* temp=head;
    // while(temp->next!=head)
    // {
    //     cout<<temp->data<<"->";
    //     temp=temp->next;
    // }
    // cout<<temp->data<<"->"<<temp->next->data<<"\n";

    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<temp->data<<"\n";
    return;
}


int deleteAtHead(node* &head)
{
    node* temp=head;
    if(temp==NULL)
    {
        cout<<"EMPTY\n";
        return 0;
    }
    if(temp->next==head)
    {
        int val=head->data;
        node* toDelete=head;
        head=NULL;
        delete(toDelete);
        return val;
    }
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    int val=head->data;
    node* toDelete=head;
    head=head->next;
    delete(toDelete);
    return val;
}

int delteAtPos(node* &head, int pos)
{
    if(pos==1)
    {
        int val=deleteAtHead(head);
        return val;
    }
    node* temp=head;
    int count=1;
    while(count<(pos-1))
    {
        temp=temp->next;
        count++;
    }
    node* toDelete=temp->next;
    temp->next=toDelete->next;
    int val=toDelete->data;
    delete(toDelete);
    return val;
}

// int deleteAtTail(node* &head)
// {
//     node* temp=head;
//     if(temp==NULL)
//     {
//         cout<<"List is Empty\n";
//         return 0;
//     }
//     if(temp->next==head)
//     {
//         int val=deleteAtHead(head);
//         return val;
//     }
//     while(temp->next->next!=head)
//     {
//         temp=temp->next;
//     }
//     node* toDelete =temp->next;
//     temp->next=head;
//     int val=toDelete->data;
//     delete(toDelete);
//     return val;
// }


int main()
{
    node* head=NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    displayCircular(head);

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    displayCircular(head);

    int pos=3;
    cout<<delteAtPos(head, pos)<<"\n";
    displayCircular(head);
    
    pos=1;
    cout<<delteAtPos(head, pos)<<"\n";
    displayCircular(head);

    // cout<<deleteAtTail(head)<<"\n";
    // displayCircular(head);

    cout<<deleteAtHead(head)<<"\n";
    displayCircular(head);
    return 0;
}