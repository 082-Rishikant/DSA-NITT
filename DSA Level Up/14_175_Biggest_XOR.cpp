#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class node
{
public:
  char data;
  bool terminal;
  unordered_map<char, node *> mp;
  node(char c)
  {
    data = c;
    terminal = false;
  }
};

node *insertTrie(node *root, vector<string> words, int n)
{
  root = new node('\0');
  for (int i = 0; i < n; i++)
  {
    string s = words[i];
    int j = 0;
    node *curr = root;
    while (s[j] != '\0')
    {
      if (curr->mp.count(s[j]) == 0)
      {
        node *newNode = new node(s[j]);
        curr->mp[s[j]] = newNode;
        curr = newNode;
      }
      else
      {
        curr = curr->mp.find(s[j])->second;
      }
      j++;
    }
    curr->terminal = true;
  }
  return root;
}

string toBinary(int n, int l)
{
  string ans = "";
  while (n)
  {
    ans = ans + to_string(n % 2);
    n = n / 2;
  }

  while (ans.size() < l)
  {
    ans = ans + "0";
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

vector<string> convertToBinary(int arr[], int n)
{
  vector<string> ans;
  // find the largest number
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, arr[i]);
  }
  // Find the length of maxi in binary form
  int l = 0;
  while (maxi)
  {
    l++;
    maxi = maxi / 2;
  }

  for (int i = 0; i < n; i++)
  {
    string s = toBinary(arr[i], l);
    ans.push_back(s);
  }

  return ans;
}

void printTrie(node *root)
{
  if (root->mp.size() == 0)
    return;
  node *temp = root;
  for (auto it : temp->mp)
  {
    cout << it.first << " ";
    printTrie(it.second);
  }
  return;
}

int toInt(string s)
{
  int ans=0; int p=1;
  for(int i=s.length()-1;i>=0;i--)
  {
    int temp=s[i]-'0';
    ans=ans+temp*p;
    p=p*2;
  }
  return ans;
}

int calculateXOR(string s, node *root)
{
  node *temp = root;
  string str = "";
  for (int i = 0; i < s.length(); i++)
  {
    int c = s[i] - '0';
    if (c == 1 && temp->mp.count('0') != 0){
      str = str + '1';
      temp=temp->mp['0'];
    }
    else if (c == 0 && temp->mp.count('1') != 0){
      str = str + '1';
      temp=temp->mp['1'];
    }
    else{
      str=str+'0';
      auto it=temp->mp.begin();
      temp=temp->mp[it->first];
    }
  }

  return toInt(str);
}

int findMaxXOR(node *root, vector<string> str, int n)
{
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int temp = calculateXOR(str[i], root);
    maxi = max(maxi, temp);
  }
  return maxi;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int arr[] = { 3, 1, 0, 25};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<string> str = convertToBinary(arr, n);

  // for(auto it:str){
  //   cout<<it<<" ";
  // }

  node *root = insertTrie(root, str, n);

  // printTrie(root);

  cout << findMaxXOR(root, str, n);

  return 0;
}