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
  return;
}

void reverseLL_Iterative(node *&head, node *prevNode, node *nextNode)
{
  while (nextNode->next != NULL)
  {
    node *temp = nextNode; // to Store the nextNode state
    temp = temp->next;     // also stroing the next state of nextNode
    nextNode->next = prevNode;
    prevNode = nextNode;
    nextNode = temp;
  }
  nextNode->next = prevNode;
  head = nextNode;
  return;
}

int main()
{
  node *head = NULL;
  insertAtHead(head, 10);
  insertAtHead(head, 11);
  insertAtHead(head, 12);
  insertAtHead(head, 13);

  print(head);
  cout << endl;

  reverseLL_Iterative(head, NULL, head); // O(n)

  print(head);
  cout << endl;
  return 0;
}