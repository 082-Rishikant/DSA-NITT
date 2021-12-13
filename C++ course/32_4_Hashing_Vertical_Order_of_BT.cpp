#include <iostream>
#include <map>
using namespace std;

void hshTable(int arr[], int n, int hd, multimap<int, int> &mp, int idx)
{
    if (idx < n)
    {
        mp.emplace(hd, idx);
        hshTable(arr, n, hd - 1, mp, 2 * idx + 1);
        hshTable(arr, n, hd + 1, mp, 2 * idx + 2);
    }
    return;
}

struct node
{
    int data;
    node *left;
    node *right;

public:
    node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

node *makeBTfromArr(int arr[], int n, int idx, node *&root)
{
    if (idx >= n)
    {
        return NULL;
    }
    root = new node(arr[idx]);
    root->left = makeBTfromArr(arr, n, 2 * idx + 1, root->left);
    root->right = makeBTfromArr(arr, n, 2 * idx + 2, root->right);
    return root;
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    return;
}

int main()
{
    multimap<int, int> mp;
    int n = 7;
    int arr[n] = {10, 7, 4, 3, 11, 14, 6};
    hshTable(arr, n, 0, mp, 0);
    for (pair<int, int> i : mp)
    {
        cout << arr[i.second] << " ";
    }
    cout << "\n";
    node *root = NULL;
    root = makeBTfromArr(arr, n, 0, root);
    inOrder(root);
    return 0;
}