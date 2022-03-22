#include <iostream>
#include <climits>
using namespace std;

class node
{
public:
  int data;
  int counter;
  node *left;
  node *right;
  node(int n)
  {
    data = n;
    counter = -1;
    left = NULL;
    right = NULL;
  }
};

// -----------My Method------------not Working
node *findTarget(node *root, int target)
{
  // base Condition
  if (root == NULL)
    return NULL;
  if (root->data == target)
  {
    root->counter = 0;
    return root;
  }

  // hypothesis
  node *lSubtree = findTarget(root->left, target);
  node *rSubtree = findTarget(root->right, target);

  // Induction
  if (lSubtree != NULL)
  {
    root->counter = root->left->counter + 1;
    return lSubtree;
  }
  else if (rSubtree != NULL)
  {
    root->counter = root->right->counter + 1;
    return rSubtree;
  }
  else
    return NULL;
}

void atDistanceKMyP(node *root, int k)
{
  if (root == NULL)
    return;
  else if (root->counter == -1)
    return;
  else if (root->counter == k)
    cout << root->data << " ";
  else if (root->counter < k)
  {
    if (root->left->counter == -1)
      root->left->counter = root->counter + 1;
    atDistanceKMyP(root->left, k);
    if (root->right->counter == -1)
      root->right->counter = root->counter + 1;
    atDistanceKMyP(root->right, k);
    return;
  }
  atDistanceKMyP(root->left, k);
  atDistanceKMyP(root->right, k);
  return;
}


// ----------Prateek Sir Method----------
void printAtK(node* root, int k){
  if(root==NULL)
    return;
  if(k==0){
    cout<<root->data<<" ";
    return;
  }
  printAtK(root->left, k-1);
  printAtK(root->right, k-1);
  return;
}

int atDistanceKPrateek(node* root, int k, int target){
  if(root==NULL)
    return -1;
  if(root->data==target)
  {
    printAtK(root, k);
    return 1;
  }

  int L=atDistanceKPrateek(root->left, k, target);
  if(L!=-1){
    if(L==k)
      cout<<root->data<<" ";
    else if(L<k){
      printAtK(root->right, k-L-1);
    }
    return L+1;
  }
  int R=atDistanceKPrateek(root->right, k, target);
  if(R!=-1){
    if(R==k)
      cout<<root->data<<" ";
    else if(R<k){
      printAtK(root->left, k-R-1);
    }
    return R+1;
  }
  return -1;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  node *root = NULL;
  root = new node(1);
  root->left = new node(2);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->left->right->left = new node(7);
  root->left->right->right = new node(8);
  root->left->right->right->left = new node(9);
  root->left->right->right->right = new node(10);
  root->right = new node(3);
  root->right->right = new node(6);

  int t = 2;
  int k = 3;

  // ------My Method---------
  // node *target = findTarget(root, t);
  // atDistanceKMyP(root, k);

  // --------Prateek Sir Method------
  atDistanceKPrateek(root, k, t);

  return 0;
}