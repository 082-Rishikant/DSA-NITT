#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int n)
    {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(node *&head, int d)
{
    node *n;
    n = new node(d);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    {
        // head=n;
        insertAtHead(head, d);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return;
}

void deleteAtn(node* &head, int val)
{
    node* temp = head;
    if (head == NULL)
    {
        cout << "The LL is alredy Empty\n";
        return;
    }
    else if (head->data == val)
    {
        head = head->next;
        head->prev = NULL;
        delete (temp);
        return;
    }
    else
    {
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                (temp->prev)->next = temp->next;
                if(temp->next!=NULL)
                {
                    (temp->next)->prev = temp->prev;
                }
                delete (temp);
                return;
            }
            temp=temp->next;
        }
        cout<<"NOT FOUND\n";
        return;
    }
}

int main()
{

    // node* head;
    // node* tail;
    // node* first;
    // node* second;
    // node* third;
    // first=new node(); // allocate memroy in heap
    // second=new node(); // allocate memroy in heap
    // third=new node(); // allocate memroy in heap
    // head=first; first->prev=NULL; first->next=second; // Link to each other
    // second->prev=first; second->next=third; // Link to each other
    // third->prev=second; third->next=NULL; tail=third ;// Link to each other
    // first->data=5; // Giving some data
    // second->data=8; // Giving some data
    // third->data=9; // Giving some data

    node *head = NULL;
    insertAtTail(head, 8); // Insert at Tail
    insertAtTail(head, 4);
    insertAtTail(head, 90);
    insertAtHead(head, 5); // Insert at Head
    display(head); // Display from head side

    deleteAtn(head, 12); // deleteAtn
    display(head);     // Display from head side
    return 0;
}