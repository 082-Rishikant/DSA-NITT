#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int n)
  {
    data = n;
    next = NULL;
  }
};

void insertAtHead(node *&head, int data)
{
  // dynamically allocatting a node and pointing it by using a node pointer
  node *newNode = new node(data);
  newNode->next = head;
  head = newNode;
  return;
}

void print(node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
  return;
}

node *mergeLL(node *head1, node *head2)
{
  node *head = NULL;
  node *temp = NULL;
  while (head1 != NULL && head2 != NULL)
  {
    if (head1->data <= head2->data)
    {
      if (head == NULL)
      {
        head = head1;
        temp = head1;
        head1 = head1->next;
        temp->next = NULL;
      }
      else
      {
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
        temp->next = NULL;
      }
    }
    else
    {
      if (head == NULL)
      {
        head = head2;
        temp = head2;
        head2 = head2->next;
        temp->next = NULL;
      }
      else
      {
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
        temp->next = NULL;
      }
    }
  }
  while (head1 != NULL)
  {
    if (head == NULL)
    {
      head = head1;
      temp = head1;
      head1 = head1->next;
      temp->next = NULL;
    }
    else
    {
      temp->next = head1;
      temp = temp->next;
      head1 = head1->next;
      temp->next = NULL;
    }
  }
  while (head2 != NULL)
  {
    if (head == NULL)
    {
      head = head2;
      temp = head2;
      head2 = head2->next;
      temp->next = NULL;
    }
    else
    {
      temp->next = head2;
      temp = temp->next;
      head2 = head2->next;
      temp->next = NULL;
    }
  }
  return head;
}


node* middlePoint(node* p1, node* p2)
{
    if(p2->next==NULL || p2->next->next==NULL)
      return p1;
    p1=p1->next;
    p2=p2->next; p2=p2->next;
    return middlePoint(p1, p2);
}

node* mergeSort(node* head, node* tail)
{
  if(head==tail)
    return head;
  node* mid=middlePoint(head, head);
  node* midNext=mid->next;
  mid->next=NULL; // seperate both the LL
  node* head1=mergeSort(head, mid);
  node* head2=mergeSort(midNext, tail);

  return mergeLL(head1, head2);
}

node* findTail(node* head)
{
  while(head->next!=NULL)
    head=head->next;
  return head;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;  cin>>n;
  node *head = NULL;
  for(int i=0;i<n;i++)
  {
    int el; cin>>el;
    insertAtHead(head, el);
  }
  print(head);

  node* tail=findTail(head);
  // cout<<head->data<<endl;
  // cout<<tail->data;

  head=mergeSort(head, tail);
  print(head);
  return 0;
}