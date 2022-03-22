#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <sstream>

const int N = 1e9 + 7;
using namespace std;

void strKeySortNumeric(vector<string> input, int col, bool isReverse)
{
  static map<int, string> mp;
  for (auto it : input)
  {
    string key;
    stringstream ss(it);
    for (int i = 1; i < col; i++)
    {
      getline(ss, key, ' ');
    }
    getline(ss, key, ' ');
    int temp = stoi(key);
    mp[temp] = it;
  }
  if (!isReverse)
  {
    for (auto it : mp)
    {
      cout << it.second << endl;
    }
  }
  else
  {
    map<int, string>::reverse_iterator it;
    for (it = mp.rbegin(); it != mp.rend(); it++)
    {
      cout << it->second << endl;
    }
  }
  return;
}

void strKeySortAlbha(vector<string> input, int col, bool isReverse)
{
  static map<string, string> mp;
  for (auto it : input)
  {
    string key;
    stringstream ss(it);
    for (int i = 1; i < col; i++)
    {
      getline(ss, key, ' ');
    }
    getline(ss, key, ' ');
    mp[key] = it;
  }
  if (!isReverse)
  {
    for (auto it : mp)
    {
      cout << it.second << endl;
    }
  }
  else
  {
    map<string, string>::reverse_iterator it;
    for (it = mp.rbegin(); it != mp.rend(); it++)
    {
      cout << it->second << endl;
    }
  }
  return;
}

int main()
{
  // vector<string> input;
  // int n;cin>>n;
  // for(int i=0;i<n;i++)
  // {
  //   string s;cin>>s;
  //   input.push_back(s);
  // }
  // int col;bool isReverse;string sortBy;
  // cin>>col>>isReverse>>sortBy;
  // if(sortBy=="numeric")
  // strKeySortNumeric({"45 34 78", "56 35 66", "23 198 5", "56 2 656"}, 3, false);
  // else
    strKeySortAlbha({"45 34 078", "56 35 66", "23 198 5", "56 2 656"}, 3, true);
  return 0;
}

//     Device at home    Threat                  Vulnerability             Risk

// 1.  Washing Machine   Wires cutted by Rats    There are some holes      High
//                                               in the Washing Machine
// 2.  Refrigerator      Cylender Fault          Not having electric       Medium
//                                               stablizer
// 3.  Smartphone        Location Tracing,       Giving the permissions    High
//                       Data storing            to Apps in Mobile

// 4.  ATM               ATM fraud               Sharing some private      High
//                                               information with fraud
//                                               caller
// 5.  Laptop            Virus attack            Installing different      High
//                                               softwares from
//                                               unverified source
