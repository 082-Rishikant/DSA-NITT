#include <iostream>
#include <unordered_map>
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

node *insert_helper(string s, node *root)
{
  int j = 0;
  node *curr = root;
  while (s[j] != '\0')
  {
    if (curr->mp.count(s[j]) == 0)
    {
      node *newNode = new node(s[j]);
      curr->mp[s[j]] = newNode;
    }
    curr = curr->mp[s[j]];
    
    j++;
  }
  curr->terminal = true;

  return root;
}

void printTrie(node *root)
{
  if (root->mp.size() == 0)
  {
    cout<<root->data<<" ";
    return;
  }
  for (auto it : root->mp)
  {
    cout << it.first << " ";
    printTrie(it.second);
  }
  return;
}

string search_in_Suffix(node *root, string s)
{
  int i = 0;
  node *temp = root;
  while (s[i] != '\0')
  {
    if (temp->mp.find(s[i]) == temp->mp.end())
      return "No";

    auto it = temp->mp.find(s[i]);
    temp = it->second;
    i++;
  }
  if (temp->terminal)
    return "Yes";
  return "No";
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string word = "apple";
  string isSuffixes[] = {"apple", "e", "pple", "mango"};

  node *root = new node('\0');

  for (int i = 0; i < word.length(); i++)
  {
    string s = word.substr(i, word.length() - i);
    root = insert_helper(s, root);
  }

  // printTrie(root);

  for (int i = 0; i < (sizeof(isSuffixes) / sizeof(isSuffixes[0])); i++)
  {
    cout << search_in_Suffix(root, isSuffixes[i]) << " ";
  }
  return 0;
}