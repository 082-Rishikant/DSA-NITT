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

void insertAtPos(node * &head, int data, int pos)
{
  if(pos<=0){
    cout<<"You are calling wrong Function You should call insertAtHead()\n";
    return;
  }
  // dynamically allocatting a node and pointing it by using a node pointer
  node * newNode=new node(data);
  node* temp=head;  int cnt=0;
  while(cnt<(pos-1)){
    temp=temp->next;
    cnt++;
  }
  newNode->next=temp->next;
  temp->next=newNode;
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

  insertAtPos(head, 14, 1);

  print(head);
  return 0;
}