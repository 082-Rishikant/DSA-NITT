#include<iostream>
#include<unordered_map>
using namespace std;

struct node
{
    int data;
    node* next;
    public:
        node(int n)
        {
            data=n;
            next=NULL;
        }
};

void findLoop(node* head)
{
    unordered_map<node* , bool> ump;
    node* temp=head;
    while(ump.count(temp)!=1 && temp!=NULL)
    {
        ump[temp]=true;
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        // cout<<"Found at: "<<temp<<endl;
        cout<<"Found at: "<<temp->data<<endl;
    }
    else
    {
        cout<<"Not Found\n";
    }
}

int main()
{
    node* head=new node(4);
    head->next=new node(3);
    head->next->next=new node(8);
    head->next->next->next=head->next;

    findLoop(head);
    return 0;
}