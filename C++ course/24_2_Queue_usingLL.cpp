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

class queue{
    node* front=NULL;
    node* back=NULL;
    public:
    void enqueue(int d)
    {
        node* newNode=new node(d);
        if(front==NULL)
        {
            front=newNode;
            back=newNode;
            return;
        }
        back->next=newNode;
        back=back->next;
        return;
    }
    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"DEQUEUE EMPTY!\n";
            return;
        }
        node* temp=front;
        front=front->next;
        cout<<"DELETED: "<<temp->data<<endl;
        delete temp;
        return;
    }
    int peek()
    {
        if(front==NULL)
        {
            cout<<"PEEK EMPTY!\n";
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if(front==NULL)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    queue q;
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(10);

    q.dequeue();
    q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
 
    cout<<q.peek()<<endl;

    cout<<q.empty()<<endl;
    return 0;
}