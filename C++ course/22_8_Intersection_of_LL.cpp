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

void intersectLL(node* &head1, node* &head2, int pos)
{
    int count=1;
    node* temp1=head1;
    node* temp2=head2;
    while (count<pos)
    {
        temp1=temp1->next;
        count++;
    }
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
    return;
}

int findInterSection(node* &head1, node* &head2)
{
    int l1=0; int l2=0;
    node* temp1=head1;
    node* temp2=head2;
    while (temp1!=NULL)
    {
        temp1=temp1->next;
        l1++;
    }
    while (temp2!=NULL)
    {
        temp2=temp2->next;
        l2++;
    }
    int pos=0;
    if(l1>l2)
    {
        temp1=head1;
        temp2=head2;
        pos=l1-l2;
    }
    else
    {
        temp1=head2;
        temp2=head1;
        pos=l2-l1;
    }
    int count=1;
    while(count<=pos)
    {
        temp1=temp1->next;
        count++;
    }
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
        {
            cout<<"Found\n";
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"Not Found\n";
    return -1;
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);

    insertAtTail(head2,7);
    insertAtTail(head2,8);

    // display(head1);
    // display(head2);

    int pos=1;
    intersectLL(head1, head2, pos);

    cout<<endl<<findInterSection(head1, head2)<<endl;
    return 0;
}