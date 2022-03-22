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

node *k_Reverse_LL(node *head, node *prevNode, node *nextNode, int k)
{
  int cnt = 0;
  while (cnt < (k - 1) && nextNode->next != NULL)
  {
    node *temp = nextNode; // to Store the nextNode state
    temp = temp->next;     // also stroing the next state of nextNode
    nextNode->next = prevNode;
    prevNode = nextNode;
    nextNode = temp;
    cnt++;
  }
  // Now reverse k nodes
  if (nextNode->next == NULL)
  {
    if (head == nextNode)
    {
      nextNode->next = NULL;
      return head;
    }
    nextNode->next = prevNode;
    head->next = NULL;
    return nextNode;
  }
  node *temp = nextNode;
  temp = temp->next;
  nextNode->next = prevNode;
  prevNode = nextNode;
  nextNode = temp;
  head->next = k_Reverse_LL(nextNode, prevNode, nextNode, k);
  return prevNode;
}

int main()
{
  node *head = NULL;
  insertAtHead(head, 10);
  insertAtHead(head, 11);
  insertAtHead(head, 12);
  insertAtHead(head, 13);
  insertAtHead(head, 14);
  insertAtHead(head, 15);
  insertAtHead(head, 16);
  // insertAtHead(head, 17);
  // insertAtHead(head, 18);

  print(head);
  cout << endl;

  int k = 3;
  head = k_Reverse_LL(head, NULL, head, k); // O(n)

  print(head);
  cout << endl;
  return 0;
}