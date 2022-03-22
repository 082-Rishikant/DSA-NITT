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

// // -----------It is used when we want to use different data type
// template<typename T>
// class node{
//   public:
//     T data;
//     node<T> * next;
//     node<T>(T n){
//       data=n;
//       next=NULL;
//     }
// };

// void insertAtHead(node<int> * &head, int data)
// {
//   // making a new node dynamicallly
//   node<int> * newNode;
//   newNode=new node<int>(data);
//   newNode->next=head;
//   head=newNode;
//   return;
// }

// void print(node<int> * head)
// {
//   while (head!=NULL)
//   {
//     cout<<head->data<<" ";
//     head=head->next;
//   }
//   return;
// }

// int main()
// {
//   // ----------- Doing manually
//   // node<int> *head=new node<int>(10);
//   // node<int> *n1=new node<int>(11);
//   // node<int> *n2=new node<int>(12);
//   // node<int> *n3=new node<int>(13);
//   // node<int> *n4=new node<int>(14);
//   // head->next=n1;
//   // n1->next=n2;
//   // n2->next=n3;
//   // n3->next=n4;
//   // n4->next=NULL;

//   // -------------Create LL using My own Function
//   // O(n)
//   node<int> * head=NULL;
//   insertAtHead(head, 10);
//   insertAtHead(head, 11);
//   insertAtHead(head, 12);
//   insertAtHead(head, 13);
//   insertAtHead(head, 14);

// // ----------Printing LL using My own function
// // O(n)
//   print(head);
//   return 0;
// }



// -----------It is used when we want to use sinle data type
class node{
  public:
    int data;
    node * next;
    node(int n){
      data=n;
      next=NULL;
    }
};

void insertAtHead(node * &head, int data)
{
  // dynamically allocatting a node and pointing it by using a node pointer
  node * newNode=new node(data);
  newNode->next=head;
  head=newNode;
  return;
}
void print(node * head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
}

int main()
{
  node * head=NULL;
  insertAtHead(head, 10);
  insertAtHead(head, 11);
  insertAtHead(head, 12);

  print(head);
  return 0;
}