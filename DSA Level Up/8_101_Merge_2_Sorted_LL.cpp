#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
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

int main()
{
  // ---------------1st Sorrted LL
  node *head1 = NULL;
  insertAtHead(head1, 9);
  insertAtHead(head1, 7);
  insertAtHead(head1, 5);
  insertAtHead(head1, 3);
  insertAtHead(head1, 1);
  print(head1);
  // --------------2nd Sorted LL
  node *head2 = NULL;
  insertAtHead(head2, 10);
  insertAtHead(head2, 8);
  insertAtHead(head2, 6);
  insertAtHead(head2, 4);
  insertAtHead(head2, 2);
  print(head2);

  node *head = mergeLL(head1, head2);
  print(head);
  return 0;
}