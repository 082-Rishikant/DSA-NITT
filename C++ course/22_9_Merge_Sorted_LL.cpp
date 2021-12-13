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

node* merge(node* &head1, node* &head2)
{
    // node* newhead=new node(2);
    node* newhead;
    node* ptr3;
    node* ptr1=head1;
    node* ptr2=head2;
    if(ptr1->data<ptr2->data)
    {
        newhead=ptr1;
        ptr3=ptr1;
        ptr1=ptr1->next;
    }
    else
    {
        newhead=ptr2;
        ptr3=ptr2;
        ptr2=ptr2->next;
    }
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        else
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        } 
    }
    while (ptr1!=NULL)
    {
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while (ptr2!=NULL)
    {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return newhead;
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    insertAtTail(head1,5);

    insertAtTail(head2,3);
    insertAtTail(head2,7);
    insertAtTail(head2,8);
    insertAtTail(head2,90);
    display(head1);
    display(head2);

    node* newhead=merge(head1, head2); // Display After Appending last k Node to starting of the node
    display(newhead);
    return 0;
}